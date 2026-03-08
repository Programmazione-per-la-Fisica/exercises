#include <TCanvas.h>
#include <TF1.h>
#include <TH1D.h>

#include <fstream>
#include <iomanip>
#include <sstream>

#include "boltzmann/boltzmann.h"

void plot_distribution_ROOT(BoltzmannSimulator const &sim, int molecules,
                            int n_interactions, int current_plot,
                            int total_plots, const int nbins = 20,
                            const double emin = 0.0, const double emax = 10.0) {
  static TCanvas *c1 = nullptr;
  if (!c1) {
    c1 = new TCanvas("c1", "Boltzmann Simulations", 1200, 800);
    c1->Divide(std::ceil(total_plots / 2.0), 2.0);
  }
  c1->cd(current_plot);

  std::string const hname{"hE_" + std::to_string(n_interactions)};
  std::string const htitle{
      "Energy distribution - N=" + std::to_string(molecules) +
      ", interactions=" + std::to_string(n_interactions)};
  TH1D *hE = new TH1D(hname.c_str(), htitle.c_str(), nbins, emin, emax);

  for (double e : sim.get_energies()) {
    hE->Fill(e);
  }

  hE->GetXaxis()->SetTitle("Energy");
  hE->GetYaxis()->SetTitle("Count");
  hE->SetLineColor(current_plot);
  hE->Draw();

  if (n_interactions > molecules * 10) {
    TF1 *fexp = new TF1("fexp", "expo", emin, emax);
    hE->Fit(fexp, "RQ");
    fexp->SetLineColor(kRed);
    fexp->Draw("same");
  }

  c1->Update();

  if (current_plot == total_plots) {
    c1->SaveAs("problemi/boltzmann_distribution/boltzmann_distributions.png");
  }
}

void plot_distribution_stdout(BoltzmannSimulator const &sim, int molecules,
                              int n_interactions, std::ostream &out = std::cout,
                              const int nbins = 20, const double emin = 0.0,
                              const double emax = 10.0) {
  std::vector<int> counts(nbins, 0);

  for (double e : sim.get_energies()) {
    if (e >= emin && e < emax) {
      int bin = static_cast<int>((e - emin) / (emax - emin) * nbins);
      if (bin >= 0 && bin < nbins) ++counts[bin];
    }
  }
  SimStats st{sim.get_stats()};
  out << "\n+++ Simulating " << molecules << " molecules +++\n";
  out << "\n=== Interaction count: " << n_interactions << " ===" << '\n';
  out << "Mean energy:   " << st.mean << '\n';
  out << "Std deviation: " << st.stddev << '\n';

  out << "Energy distribution:\n";
  for (int i = 0; i < nbins; ++i) {
    double low{emin + i * (emax - emin) / nbins};
    double high{low + (emax - emin) / nbins};
    int barlen = static_cast<int>(
        50.0 * counts[i] /
        (*std::max_element(counts.begin(), counts.end()) + 1e-9));

    out << std::fixed << std::setprecision(1) << "[" << std::setw(4) << low
        << " - " << std::setw(4) << high << "] " << std::string(barlen, '#')
        << " (" << counts[i] << ")\n";
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0]
              << " molecules interactions[list(comma-separated)]"
              << "Example: " << argv[0] << " 1000 1000,10000,100000" << '\n';
    return 1;
  }

  int molecules{std::stoi(argv[1])};
  std::string s_interaction_list{argv[2]};
  std::vector<int> interaction_list;
  std::stringstream ss(s_interaction_list);
  std::string token;
  while (std::getline(ss, token, ',')) {
    if (!token.empty())
      interaction_list.push_back(
          std::stoll(token));  // Parse from list of interactions (e.g.
                               // "1000,10000,100000")
  }

  std::ofstream fout("output.txt");
  std::default_random_engine gen;
  int pad{1};

  for (auto n_interactions : interaction_list) {
    BoltzmannSimulator sim(molecules, gen);
    sim.run(n_interactions);

    // Plot using ostream (default stdout, can be redirected to file)
    plot_distribution_stdout(sim, molecules, n_interactions, fout);
    // Plot using ROOT
    plot_distribution_ROOT(sim, molecules, n_interactions, pad,
                           interaction_list.size());
    ++pad;
  }
  return 0;
}
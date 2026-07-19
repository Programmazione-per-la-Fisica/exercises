#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<std::string> trova_ricette_con(
    const std::string& ingrediente,
    const std::map<std::string, std::vector<std::string>>& ricettario) {
  std::vector<std::string> elenco_ricette;

  auto it = ricettario.begin();
  while (it != ricettario.end()) {
    // select the ingredient
    auto ingredienti = it->second;
    // search for it
    auto pos = std::find(ingredienti.begin(), ingredienti.end(), ingrediente);
    if (pos != ingredienti.end()) {
      // if found add it in the list
      elenco_ricette.push_back(it->first);
    }
    ++it;
  }
  return elenco_ricette;
}

TEST_CASE("testing the trova_ricetta_con function") {
  std::map<std::string, std::vector<std::string>> ricettario = {
      {"pasta al pomodoro", {"pasta", "pomodoro", "olio", "sale"}},
      {"pizza margherita",
       {"farina", "lievito", "pomodoro", "aglio", "olio", "sale",
        "mozzarella"}},
      {"caprese", {"pomodoro", "mozzarella", "olio", "sale", "origano"}},
      {"friggione", {"sale", "pepe", "cipolla", "pomodoro"}}};
  CHECK(trova_ricette_con("farina", ricettario) ==
        std::vector<std::string>{"pizza margherita"});
  CHECK(trova_ricette_con("pane", ricettario).empty() == true);
  CHECK(trova_ricette_con("pomodoro", ricettario) ==
        std::vector<std::string>{"caprese", "friggione", "pasta al pomodoro",
                                 "pizza margherita"});
  CHECK(trova_ricette_con("olio", ricettario) ==
        std::vector<std::string>{"caprese", "pasta al pomodoro",
                                 "pizza margherita"});
  CHECK(trova_ricette_con("mozzarella", ricettario) ==
        std::vector<std::string>{"caprese", "pizza margherita"});
}
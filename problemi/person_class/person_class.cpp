#include <iostream>
#include <string>

class person {
 private:
  std::string m_name;
  std::string m_surname;

 public:
  person(std::string const& name, std::string const& surname)
      : m_name{name}, m_surname{surname} {}

  // Getters
  std::string name() const { return m_name; }
  std::string surname() const { return m_surname; }
};

int main() {
  person p("Simone", "Balducci");
  std::cout << "Name: " << p.name() << ", " << "Surname: " << p.surname()
            << '\n';

  // We don't need to define the copy constructor; the compiler takes care of if
  person q(p);
  std::cout << "Name: " << q.name() << ", " << "Surname: " << q.surname()
            << '\n';
  q = {"Samuele", "Lanzi"};
  std::cout << "Name: " << q.name() << ", " << "Surname: " << q.surname()
            << '\n';
}

#include <iostream>
#include <string>

class person {
 private:
  std::string m_name;
  std::string m_surname;

 public:
  person(std::string const& name, std::string const& surname)
      : m_name{name}, m_surname{surname} {}

  void name(std::string const& name) { m_name = name; }
  std::string name() const { return m_name; }
  void surname(std::string const& surname) { m_surname = surname; }
  std::string surname() const { return m_surname; }
};

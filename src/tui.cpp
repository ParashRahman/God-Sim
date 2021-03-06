#include <iostream>

#include "person_stats.h"
#include "tui.h"

typedef unsigned long long ID_type;

TUI::TUI() {
  current_node = ft.root;
}

void TUI::start_tui() {
  print_current_state();

  ID_type input;

  while (std::cin >> input) {
    ft.visit_person(input);
    current_node = ft.get_person_from_id(input);
    print_current_state();
  }
}

void TUI::print_current_state() {
  std::cout << std::string(12, '=') << std::endl;

  std::cout << "person: " << current_node->parent->toString() << std::endl;

  if (current_node != ft.root) {
    std::cout << "mother: " << ft.get_person_from_id(current_node->parent->get_mother())->parent->toString() << std::endl;
    std::cout << "father: " << ft.get_person_from_id(current_node->parent->get_father())->parent->toString() << std::endl;
  }

  std::cout << "stats: " << std::endl;
  for (Stat s : PersonStats::iterable_stat_enum) {
    std::cout << "  " << PersonStats::stat_to_name[s] << " " << current_node->parent->get_stats().stat_to_value[s] << std::endl;
  }
  
  std::cout << "children: " << std::endl;
  for (int c = 0; c < current_node->children.size(); ++c) {
    std::cout << "  " << c << ". " << current_node->children[c]->parent->toString() << " m: " << ft.get_person_from_id(current_node->children[c]->parent->get_mother())->parent->toString() << " f: " << ft.get_person_from_id(current_node->children[c]->parent->get_father())->parent->toString() << std::endl;
  }
  
  std::cout << std::string(12, '=') << std::endl;
}


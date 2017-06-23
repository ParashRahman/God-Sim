#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Person;
typedef std::shared_ptr<Person> person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;
typedef std::vector<ID_type> friend_vector;

class Person {
 private:
  std::string name;
  static ID_type CURRENT_ID;
  ID_type my_id;
  children_map child_map;
  gen_type my_generation;
  friend_vector friends;
  
 public:
  Person(std::string name, gen_type generation);
  void add_children(person_ptr spouse, std::vector<person_ptr> children);
  void add_friendships(person_ptr friendo);
  ID_type get_ID();
  gen_type get_generation();
  
};

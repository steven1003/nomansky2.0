#include <string>
#include <SFML/Graphics.hpp>

class Recipes{
public:
 std::vector<std::string> getInput();
 std::string getName();
 RscEntity getOutput();
 RscEntity craftRecipe(RscEntity res1, int numOfRes);

private:
  std::string name;
  std::vector<std::string> input;
  RscEntity* output;
  int numOf;
};

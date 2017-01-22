class Recipes{
public:
 sf::Vector2f<std::string,int> getInput()
 std::string getName();
 RscEntity getOutput();
 RscEntity craftRecipe();

private:
  std::string name;
  sf::Vector2f<std::string,int> input;
  RscEntity* output;
  int numOf;
}

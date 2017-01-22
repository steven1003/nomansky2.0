class Recipes{
public:
 std::vector<std::string> getInput();
 std::string getName();
 RscEntity getOutput();
 RscEntity craftRecipe();

private:
  std::string name;
  std::vector<std::string> input;
  RscEntity* output;
  int numOf;
}

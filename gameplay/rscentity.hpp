class RscEntity{
public:
  std::string getName();
  int getNum();
  sf::Texture getTexture();
  void setNum();




private:
  int numOf;
  sf::Texture rsctext;
  std::string name;



}

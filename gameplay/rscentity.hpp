class RscEntity{
public:
  std::string getName();
  int getNum();
  sf::Texture getTexture();
  void addItem(int num);
  void setTexture(sf::Texture);



private:
  int numOf;
  sf::Texture rsctext;
  std::string name;



};

#include<iostream>
#include<cmath>

class Point
{
public:
	float x;
	float y;

	Point(): x(0), y(0) {}

	float Dis_Euclidiana(float x2, float y2) const {
		float Dx = x - x2;
		float Dy = y - y2;
		return std::sqrt(Dx * Dx + Dy * Dy);
	}

	float Dis_Manhattan(float x2, float y2) const {
		return std::fabs(x - x2) + std::fabs(y - y2);
	}
};
	Point read_Point(const std::string& texto) {

		Point p;
		std::cout << texto;
		std::cin >> p.x >> p.y;
		return p;
	}

	void Dist_Look(const Point& p1, float x2, float y2) {
		std::cout << "\nDistancia euclidiana: " << p1.Dis_Euclidiana(x2, y2) << std::endl;
		std::cout << "Distancia de Manhattan: " << p1.Dis_Manhattan(x2, y2) << std::endl;
	}

int main()
{
	Point p1 = read_Point("Digite as coordenadas do ponto(x/y): ");

	float x2, y2;
	std::cout << "Digite as coordenadas do outro ponto(x/y): ";
	std::cin >> x2 >> y2;

	Dist_Look(p1, x2, y2);

	return 0;
};
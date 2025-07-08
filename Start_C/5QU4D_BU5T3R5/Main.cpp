#include<iostream>
#include<string>
#include<locale>

class Usuario
{
	public:
		std::string nome;
		std::string sobrenome;

		std::string nomeCompleto()
		{
			return nome + " " + sobrenome;
		};
};

class UsuarioMaster : public Usuario 
{
	public:
		std::string nome;
		std::string sobrenome;

		std::string nomeCompleto()
		{
			return "Master: " + nome + " " + sobrenome;
		};
};

int main()
{
	setlocale(LC_ALL, "pt_BR");
	std::cout << "Hello World\n";
	UsuarioMaster u;
	std::cout << "digite o seu nome:\n";
	std::cin >> u.nome;
	std::cout << "digite o seu sobrenome:\n";
	std::cin >> u.sobrenome;
	std::cout << "Bem vindo " << u.nomeCompleto();
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Game_interface.h"
#include "Net.h"
#include "Activation.h"
#include "Layer.h"
#include "Players.h"
#include "Utils.h"


namespace fs = std::filesystem;


int main() {

	int mode = 0;			 // 1 - ���� ������ ��������, -1 - ���� ������ ����������, 0 - �� ����������
	int player = 0;			 // 1 - ������� (�������� �����) ������ �� ��������, -1 - �� ������, 0 - �� ����������
	bool human_move = false;	// ���� �� �� ���� �� ��������

	TikTakToe_engine game;    //�������������� ����

	
	Player* second_opponent;  //��� ������(���������)


	sf::RenderWindow window(sf::VideoMode(600, 650), "TikTakToe");									//������� ����

	sf::Texture players_image;																	// ������� �������� ��������� � �������
	auto path_to_players_images = fs::current_path().parent_path() / "images" / "tiktak.png";
	std::string path_string_players_image{ path_to_players_images.u8string() };
	players_image.loadFromFile(path_string_players_image);										//������� ������ ��������� � �������

	sf::Sprite player_choice[2];

	for (size_t i = 0; i < 2; i++)								// ������� ������� �������� � ������ ��� ������ � ����. ������������� ����������� � �������
	{
		player_choice[i].setTexture(players_image);
		player_choice[i].setPosition(50 + 300 * i, 180);    
	}

	sf::Texture mode_image;										// ������� ���� ������ ���� ����
	auto path_to_mode_images = fs::current_path().parent_path() / "images" / "mode.png";
	std::string path_string_mode_image{ path_to_mode_images.u8string() };
	mode_image.loadFromFile(path_string_mode_image);

	sf::Sprite mode_choice[2];

	mode_choice[0].setTexture(mode_image);
	mode_choice[0].setPosition(235, 250);

	mode_choice[1].setTexture(mode_image);
	mode_choice[1].setPosition(205, 280);						// ������� ������� ������ ������ ���� ���� ( ������ �������� ��� ������ ����������). ������������� ����������� � �������

	sf::Texture background_texture;
	auto path_to_background_images = fs::current_path().parent_path() / "images" / "background.png";
	std::string path_string_background_image{ path_to_background_images.u8string() };
	background_texture.loadFromFile(path_string_background_image);

	sf::Sprite background;
	background.setTexture(background_texture);					// ������� ���������

	sf::Sprite board[9];										// ������� ������, ������� ������ � ���� �������� � ������. �������� ������ ����
	
	for (size_t i = 0; i < 9; i++)
	{
		board[i].setPosition(200 * ( i % 3), 200 * int(i/3));
		board[i].setTextureRect(sf::IntRect(0,0,200, 200));
	}															// ������������ ������� �� �����, ���� ��� ��������


	sf::Texture lines_image;																	// ������� ������ ����� - �����������
	auto path_to_lines_images = fs::current_path().parent_path() / "images" / "winner.png";
	std::string path_string_lines_image{ path_to_lines_images.u8string() };
	lines_image.loadFromFile(path_string_lines_image);										//��������� �����

	sf::Sprite winner_lines[2];

	for (size_t i = 0; i <2; i++)
	{
		winner_lines[i].setTexture(lines_image);
	}
	


	while (window.isOpen())
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);			// �������������� �����
		sf::Event event;														

		if (mode==1){human_move = true;}										// ���� ������ ����� - �������, �� ������ ��� ��������


		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}


			if ((event.type == sf::Event::MouseButtonPressed)&& (event.mouseButton.button == sf::Mouse::Left) && (mode==0) )		// ��������, ��� ������ ������ ���
			{
				for (size_t i = 0; i < 2; i++)
					{
						if (mode_choice[i].getGlobalBounds().contains(mouse_position.x, mouse_position.y)) 
						{mode = 1 - i * 2;	}

					}
				if (mode==1)											// ���� mode = 1 , �� ������ ����� - �������, ����� - ��������� ����
				{
					second_opponent = new Human();
				}				
				else
				{
						Net* computer = new Net(1, 1, 1, 9);
						computer->add_layer(new Layer::Dense(64, new  Initializator::FromFile("layer_1_9x64_w.txt"), new  Initializator::FromFile("layer_1_9x64_b.txt")));
						computer->add_layer(new Activation::Relu());
						computer->add_layer(new Layer::Dense(32, new  Initializator::FromFile("layer_2_64x32_w.txt"), new  Initializator::FromFile("layer_2_64x32_b.txt")));
						computer->add_layer(new Activation::Relu());
						computer->add_layer(new Layer::Dense(1, new  Initializator::FromFile("layer_3_32x1_w.txt"), new Initializator::FromFile("layer_3_32x1_b.txt")));
						computer->add_layer(new Activation::Tanh());
						second_opponent = computer;

				}
				
			}   
			else if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && !player)    // ��������, �� ���� ����� ������ �������� �����
			{
				for (size_t i = 0; i < 2; i++)
				{
					if (player_choice[i].getGlobalBounds().contains(mouse_position.x, mouse_position.y))
					{
						player = 1 - i * 2;
					}
				}

				if (player ==  1) { human_move = true;}						 // ���� �������� ����� - �������, �� ���� �� ���� ����
				if (player == -1) {	mode == 1 ? human_move = true : human_move = false;	}  // ���� �������� ����� �����, �� ���������, �������� �� ������ ����� ���������. ���� ��, �� �� ������ ���� �� ���� ����
								
			}
			else if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && (human_move==1))     //���� ��� ��������, �� ���������, ����� �� ������� ���, ���� �������, �� ������
			{
				for (short i = 0; i < 9; i++)
				{
					if (board[i].getGlobalBounds().contains(mouse_position.x, mouse_position.y))
					{
						if ((game.allowed_moves(i + 1)))
						{
							game.make_move(i+1);
							mode == 1 ? human_move = true : human_move = false;

						}
					}
				}
			}

		
		}
		
		if ((player!=0) && (!human_move))	// ���� ������ ����� - ����, �� ���������, ������� �� �� ��� ������ � �� ��� �� ������ ��������
		{
			short move;
			move = second_opponent->choose_move(game);						//�������� ���������, �� ������ ����, ���
			if (game.allowed_moves(move)){game.make_move(move);	}			// ���� �������� ������� ������ ���, �� ������ ���
			human_move = true;
		}

		if (!mode)							
		{
			for (size_t i = 0; i < 2; i++)
			{
				if (mode_choice[i].getGlobalBounds().contains(mouse_position.x, mouse_position.y))
				{
					mode_choice[i].setTextureRect(sf::IntRect(139 * i, 21, 138 + i * 56, 22));
				}
				else
				{
					mode_choice[i].setTextureRect(sf::IntRect(139 * i, 0, 138 + i * 56, 22));
				}
			}
		}
		if (!player) {
			for (size_t i = 0; i < 2; i++)
			{
				if (player_choice[i].getGlobalBounds().contains(mouse_position.x, mouse_position.y))
				{
					player_choice[i].setTextureRect(sf::IntRect(200 * i, 200, 200, 200));
				}
				else
				{
					player_choice[i].setTextureRect(sf::IntRect(200 * i, 0, 200, 200));
				}

			}
		}

		if (game.get_winner() != -2)
		{
			int winner_line = return_winner_line(game);
			int winner = game.get_winner();

			switch (winner_line)
			{
			case 0:
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 600, 10));
				winner_lines[0].setPosition(0, 95);
				break;
			case 1:
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 600, 10));
				winner_lines[0].setRotation(90);
				winner_lines[0].setPosition(105, 0);
				break;
			case 2:
				winner_lines[0].setPosition(0, 295);
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 600, 10));
				break;
			case 3:
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 600, 10));
				winner_lines[0].setRotation(90);
				winner_lines[0].setPosition(305, 0);
				break;
			case 4:
				winner_lines[0].setPosition(0, 495);
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 600, 10));
				break;
			case 5:
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 600, 10));
				winner_lines[0].setRotation(90);
				winner_lines[0].setPosition(505, 0);
				break;
			case 6:
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 833, 10));
				winner_lines[0].setRotation(45);
				winner_lines[0].setPosition(9, 2);
				break;
			case 7:
				winner_lines[0].setTextureRect(sf::IntRect(0, 0, 833, 10));
				winner_lines[0].setRotation(-45);
				winner_lines[0].setPosition(3, 591);
				break;
			default:
				break;
			}
			
			switch (winner)
			{
			case 0:
				winner_lines[1].setTextureRect(sf::IntRect(0,94, 300, 45));
				winner_lines[1].setPosition(170, 602);
				break;
			case 1:
				winner_lines[1].setTextureRect(sf::IntRect(0, 10, 292, 42));
				winner_lines[1].setPosition(154, 604);
				break;
			case -1:
				winner_lines[1].setTextureRect(sf::IntRect(0, 52, 300, 42));
				winner_lines[1].setPosition(150, 604);
				break;
			default:
				break;
			}

		}

		for (size_t i = 0; i < 9; i++)
		{
			if (game.get_state()[i])
			{
				board[i].setTexture(players_image);
				board[i].setTextureRect(sf::IntRect(0, 0, 200, 200));
			}

			if (game.get_state()[i] == -1)
			{
				board[i].setTexture(players_image);
				board[i].setTextureRect(sf::IntRect(200, 0, 200, 200));
			}
		}



		window.clear(sf::Color::White);
		if (!mode)
		{
			for (size_t i = 0; i < 2; i++)
			{
				window.draw(mode_choice[i]);
			}
		}

		else if (!player)
		{
			for (size_t i = 0; i < 2; i++)
			{
				window.draw(player_choice[i]);
			}
		}

		else
		{
			window.draw(background);

			for (size_t i = 0; i < 9; i++)
			{
				window.draw(board[i]);

				if (game.get_winner()!=-2)
				{	
					if (game.get_winner()!=0)
					{
						for (size_t i = 0; i < 2; i++)
						{
							window.draw(winner_lines[i]);
						}
					}
					else
					{
						window.draw(winner_lines[1]);
					}
					
				}
			}
		}
		
		window.display();
	}
	
	//Interface inter("Vs-computer");
	//inter.play_game();


	

//	system("pause");
	return 0;
}
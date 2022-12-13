	#ifndef WILDPOKEMON_H
	#define WILDPOKEMON_H
	#include <iostream>
	#include <cmath>
	#include <string>
	#include "Trainer.h"

	using namespace std;
	class WildPokemon: public GameObject {
        enum WildPokemonStates {
            DIED = 0,
            INGRASS = 1,
            FOLLOWING_TRAINER = 2,

        };
	public:
	  WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);

	  void follow(Trainer* t);
	  bool Update();
	  void ShowStatus();
	  bool ShouldBeVisible();
	  bool IsAlive();
	  virtual ~WildPokemon();
        bool get_variant();
        bool get_in_combat();
        double get_attack();
        double get_health();
	protected:
	  double attack = 5;
	  double health = 2;
	  bool variant = false;
	  string name;
	  Trainer* current_trainer;
	  bool in_combat = false;
	};


	#endif

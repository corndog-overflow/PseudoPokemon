	#ifndef WILDPOKEMON_H
	#define WILDPOKEMON_H
	#include <iostream>
	#include <cmath>
	#include <string>
	#include "Trainer.h"

	using namespace std;
	class WildPokemon: public GameObject {
        enum WildPokemonStates {
            DEAD = 0,
            IN_ENVIRONMENT = 1,
            IN_TRAINER = 2,

        };
	public:
	  WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);

	  void follow(Trainer* t);
	  bool Update();
	  void ShowStatus();
	  bool ShouldBeVisible();
	  bool IsAlive();
	  virtual ~WildPokemon();
	protected:
	  double attack = 5;
	  double health = 2;
	  bool variant = false;
	  string name;
	  Trainer* current_trainer;
	  bool in_combat = false;
	};


	#endif

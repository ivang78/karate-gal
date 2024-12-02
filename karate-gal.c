#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "galaksija.h"

#define arm_free 			0
#define arm_punch_forward 	1
#define arm_free_up 		2
#define arm_punch_up 		3 	
#define leg_free 			0
#define leg_kick_forward 	1
#define leg_kick_up			2
#define leg_step			3
#define action_free						0
#define action_attack_punch_forward 	1
#define action_attack_punch_up 			2
#define action_attack_kick_forward 		3
#define action_attack_kick_up		 	4
#define action_step					 	5

char x_pos, y_pos, x_enemy, c;
char sprite[384] = {
  0xc0, 0xc0, 0xc0, 0xef, 0xf7, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xef, 0xf7, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0xca, 0xff, 0xd3, 0xe8, 0xd4, 0xc0, 0xc0, 0xc0, 0xc0, 0xef, 0xf7, 0xc1, 0xc0, 0xf0,
  0xc0, 0xe0, 0xfc, 0xfe, 0xfd, 0xe4, 0xd0, 0xc0, 0xc0, 0xc0, 0xf8, 0xfe, 0xfd, 0xe4, 0xf0, 0xd0, 0xc0, 0xf8, 0xfc, 0xff, 0xdc, 0xdf, 0xc1, 0xc0, 0xc0, 0xc0, 0xf8, 0xfe, 0xfd, 0xe4, 0xfe, 0xc7,
  0xc0, 0xca, 0xff, 0xff, 0xfd, 0xd7, 0xc3, 0xc0, 0xc0, 0xca, 0xff, 0xff, 0xfd, 0xd7, 0xc3, 0xc3, 0xc0, 0xef, 0xff, 0xff, 0xfe, 0xe0, 0xfc, 0xdc, 0xc0, 0xca, 0xff, 0xff, 0xfd, 0xd7, 0xc1, 0xc0,
  0xc0, 0xc0, 0xf8, 0xe3, 0xd3, 0xd0, 0xc0, 0xc0, 0xc0, 0xc0, 0xf8, 0xe3, 0xd3, 0xf0, 0xf0, 0xd0, 0xc0, 0xc0, 0xfa, 0xe3, 0xf1, 0xff, 0xc7, 0xc0, 0xc0, 0xc0, 0xf8, 0xe3, 0xd3, 0xd0, 0xc0, 0xc0,
  0xc0, 0xe8, 0xff, 0xdf, 0xff, 0xfd, 0xc0, 0xc0, 0xc0, 0xe8, 0xff, 0xdf, 0xcf, 0xcf, 0xcf, 0xcf, 0xc0, 0xf8, 0xff, 0xcf, 0xc7, 0xc1, 0xc0, 0xc0, 0xc0, 0xf8, 0xff, 0xcf, 0xef, 0xfd, 0xd0, 0xc0,
  0xc0, 0xfe, 0xff, 0xc0, 0xea, 0xff, 0xd4, 0xc0, 0xc0, 0xfe, 0xff, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0xfa, 0xff, 0xc7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfa, 0xff, 0xc7, 0xc0, 0xc0, 0xcb, 0xff, 0xf4,
  0xc0, 0xc0, 0xc2, 0xfb, 0xdf, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc2, 0xfb, 0xdf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe8, 0xd4, 0xe3, 0xff, 0xc5, 0xc0, 0xc0, 0xf0, 0xc0, 0xc2, 0xfb, 0xdf, 0xc0, 0xc0, 0xc0,
  0xc0, 0xe0, 0xd8, 0xfe, 0xfd, 0xfc, 0xd0, 0xc0, 0xe0, 0xf0, 0xd8, 0xfe, 0xfd, 0xf4, 0xc0, 0xc0, 0xc0, 0xc2, 0xef, 0xec, 0xff, 0xfc, 0xf4, 0xc0, 0xcb, 0xfd, 0xd8, 0xfe, 0xfd, 0xf4, 0xc0, 0xc0,
  0xc0, 0xc3, 0xeb, 0xfe, 0xff, 0xff, 0xc5, 0xc0, 0xc3, 0xc3, 0xeb, 0xfe, 0xff, 0xff, 0xc5, 0xc0, 0xec, 0xfc, 0xd0, 0xfd, 0xff, 0xff, 0xdf, 0xc0, 0xc0, 0xc2, 0xeb, 0xfe, 0xff, 0xff, 0xc5, 0xc0,
  0xc0, 0xc0, 0xe0, 0xe3, 0xd3, 0xf4, 0xc0, 0xc0, 0xe0, 0xf0, 0xf0, 0xe3, 0xd3, 0xf4, 0xc0, 0xc0, 0xc0, 0xcb, 0xff, 0xf2, 0xd3, 0xf5, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe3, 0xd3, 0xf4, 0xc0, 0xc0,
  0xc0, 0xc0, 0xfe, 0xff, 0xef, 0xff, 0xd4, 0xc0, 0xcf, 0xcf, 0xcf, 0xcf, 0xef, 0xff, 0xd4, 0xc0, 0xc0, 0xc0, 0xc2, 0xcb, 0xcf, 0xff, 0xf4, 0xc0, 0xc0, 0xe0, 0xfe, 0xdf, 0xcf, 0xff, 0xf4, 0xc0,
  0xc0, 0xe8, 0xff, 0xd5, 0xc0, 0xff, 0xfd, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc2, 0xff, 0xfd, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xcb, 0xff, 0xf5, 0xf8, 0xff, 0xc7, 0xc0, 0xc0, 0xcb, 0xff, 0xf5,
};
char bg[96] = {
  0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xc6, 0xef, 0xdc, 0xd0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
  0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xcc, 0xc1, 0xc0, 0xc0, 0xcb, 0xc6, 0xcc, 0xd0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
  0xcc, 0xc3, 0xcc, 0xcc, 0xcc, 0xc6, 0xc9, 0xcc, 0xcc, 0xcc, 0xc3, 0xcc, 0xcc, 0xcc, 0xc3, 0xcc, 0xcc, 0xcc, 0xc6, 0xc9, 0xcc, 0xcc, 0xcc, 0xc3, 0xcc, 0xcc, 0xcc, 0xc6, 0xc9, 0xcc, 0xcc, 0xcc
};
char arms[6] = {
	arm_free, arm_punch_forward, arm_punch_up, arm_free, arm_free_up, arm_free
};
char legs[6] = {
	leg_free, leg_free, leg_free, leg_kick_forward, leg_kick_up, leg_step
};
char attack;
int attack_time, check_attack_time;
char hits[2];
char enemy_move = 0;
char eneny_accuracy = 80;
char attack_delay = 20;
char possible_attack = 0;
unsigned int rnd, tm, tm2;
char cont = 1;

/*
	draw background
*/
void draw_bg () {
	for (char i = 0; i < 32; i++) {
		z80_bpoke(SCREEN_ADDR + (13 << 5) + i, 143);
	}
	for (char i = 0; i < 96; i++) {
		z80_bpoke(SCREEN_ADDR + 32 + i, bg[i]);
	}
}

/*
	draw hits
*/
void draw_hits (char show_hit) {
	gal_gotoxy(6,14); gal_puts("YOU");
	gal_gotoxy(22,14); gal_puts("ENEMY");
	for (char i = 0; i < 11; i++) {
		z80_bpoke(SCREEN_ADDR + (15 << 5) + i + 2, 32);
		if (i < hits[0]) {
			z80_bpoke(SCREEN_ADDR + (15 << 5) + i + 2, 143);
		}
		z80_bpoke(SCREEN_ADDR + (15 << 5) + i + 19, 32);
		if (i < hits[1]) {
			z80_bpoke(SCREEN_ADDR + (15 << 5) + i + 19, 143);
		}
	}
	if (show_hit == 1) {
		gal_gotoxy(14, 5); gal_puts("HIT!");
	}
	if (hits[0] == 0 || hits[1] == 0) {
		if (hits[1] == 0) {
			gal_gotoxy(14, 5); gal_puts("WIN!");
		} else {
			gal_gotoxy(13, 5); gal_puts("LOOSE");
		}
		do {
			
		} while (getk() != 10);
		c = 255;
	}
}

/*
	draw sprite
	character: 0 - you, 1 - enemy
	xp: x position
	action: action (see constants)
*/
void draw_sprite (char character, char xp, char action) {
	char p0 = arms[action]<<3;
	char p1 = legs[action]<<3;	
	int addr0 = SCREEN_ADDR + (y_pos << 5) + xp;
	for (char j = 0; j < 6; j++) {
		if (arms[action] != legs[action] && j == 3) {
			p0 = p1;
		}
		for (char i = 0; i < 8; i++) {
			z80_bpoke(addr0 + (j << 5) + i, sprite[p0 + (j << 5) + i + (character * 192)]);
		}
	}
}

/*
	Welcome frame
*/
void frame() {
	char j;
	gal_gotoxy(10 ,3); gal_puts("KARATE GAME");
	gal_gotoxy(10 ,4); 
	for (j = 0; j < 11; j++) {
		gal_putc(140);
	}
	gal_gotoxy(4,6);  gal_puts("ARROW LEFT, RIGHT - MOVE");
	gal_gotoxy(4,7);  gal_puts("ARROW UP, DOWN - KICK");
	gal_gotoxy(4,8);  gal_puts("Q, A - PUNCH");
	gal_gotoxy(4,9);  gal_puts("DEL - QUIT");
	gal_gotoxy(4,10); gal_puts("PRESS ENTER");	
	gal_gotoxy(4,13); gal_puts("BY IVAN ILYICHEV 2024"); 
	do {
	} while (getk() != 10);
}

/*
	Emeny action
*/
void enemy_action () {
	char redraw = 0;
	char attack_enemy = 0;
	char attack_state = 0;
	tm2 = clock();
	if (tm2 < tm) { // overload time counter
		tm = 0; 
	}
	// movement
	if (tm2 - tm > 250 && enemy_move == 0) {
		enemy_move = 1;
	}
	if (tm2 - tm > 30 && enemy_move == 1) {		
		if (x_enemy - x_pos > 6) {
			x_enemy--;
			redraw = 1;
		} else {
			enemy_move = 0;
			redraw = 0;
		}
	}
	// attacks
	if (x_enemy - x_pos <= 6) {
 		if (redraw == 0 && tm2 - tm > (rand() / (RAND_MAX / attack_delay)) + attack_delay) { // enemy try to attack
			attack_enemy = (rand() / (RAND_MAX / 4)) + 1;
			redraw = 1;
			if (attack > 0) { // you attacked
				if (attack_time < tm2) { // you attack first
					if (attack == attack_enemy) { //same attack
						attack_state = 0; // block attack, nothing happens
					} else { // different attack
						if ((rand() / (RAND_MAX / 100)) < 50) {
							attack_state = 1; // you hits
						} else {
							attack_state = 2; // enemy hits
						}
					}
				} else { // enemy attack first 
					if ((rand() / (RAND_MAX / 100)) < (eneny_accuracy - 30)) {
						attack_state = 2; // enemy hits
					}
				}
			} else { // you are not attacked
				if ((rand() / (RAND_MAX / 100)) < eneny_accuracy) {
					attack_state = 2; // enemy hits
				}
			}
		} else if (attack > 0) { // no emeny attack, you attacked
			if ((rand() / (RAND_MAX / 100)) < eneny_accuracy) {
				attack_state = 1; // you hits
			}
		}
	}
	// redraw sprite
	if (redraw == 1) {
		tm = tm2;
		if (attack_enemy > 0) {
			draw_sprite(1, x_enemy, attack_enemy);
		} else {
			draw_sprite(1, x_enemy, action_step);
		}
		for (int i = 0; i <= 700;i++) {}
		draw_sprite(1, x_enemy, action_free);
		gal_gotoxy(14, 5); gal_puts("    ");
	}
	// redraw hit
	if (attack_state > 0) {
		if (attack_state == 1) {
			hits[1]--;
		} else if (attack_state == 2) {
			hits[0]--;			
		} 
		draw_hits(1);
	}
}

/*
	Main function
*/
int main() {	
	rnd = z80_wpeek(RND_ADDR);
	srand(rnd);
	gal_cls();
	frame();
	do {
		gal_cls();
		draw_bg ();
		tm = clock();
		x_pos = 0;
		x_enemy = 23;
		y_pos = 7;
		attack = 0;
		hits[0] = 11;
		hits[1] = 11;
		draw_sprite(0, x_pos, action_free);
		draw_sprite(1, x_enemy, action_free);
		draw_hits(0);	
		do {		
			c = getk();
			if (c == 43 || c == 44 || c == 'Q' || c == 'A') { // common attacks actions
				check_attack_time = clock();
				possible_attack = 0;
				if (attack == 0 && (check_attack_time - attack_time > attack_delay || check_attack_time < attack_time)) {
					possible_attack = 1;
					attack_time = check_attack_time;
				}
			}
			switch (c) {
				case 45: // left 
					attack = 0;
					if (x_pos > 0) {
						x_pos--;
					}
					draw_sprite(0, x_pos, action_step);
					draw_sprite(0, x_pos, action_free);
					break;
				case 46: // right
					attack = 0;
					if (x_enemy - x_pos > 6) {
						x_pos++;
					}
					draw_sprite(0, x_pos, action_step);
					draw_sprite(0, x_pos, action_free);
					break;
				case 43: // up, kick up
					if (possible_attack == 1) {
						attack = action_attack_kick_up;
					}
					break;
				case 44: // down, kick forward
					if (possible_attack == 1) {
						attack = action_attack_kick_forward;
					}
					break;
				case 'Q': // punch up
					if (possible_attack == 1) {
						attack = action_attack_punch_up;
					}
					break;				
				case 'A': // punch forward
					if (possible_attack == 1) {
						attack = action_attack_punch_forward;
					}
					break;
				case 0:
					if (attack > 0) {
						attack = action_free;
						draw_sprite(0, x_pos, action_free);
					}
					break;
				case 67: // del
					cont = 0;
					c = 255;
					break;
				default:
					break;
			}
			if (attack > 0) {
				draw_sprite(0, x_pos, attack);
			}
			enemy_action();
		} while (c != 255);
		if (hits[1] == 0 && eneny_accuracy < 100) { // if you win add enemy accuracy
			eneny_accuracy = eneny_accuracy + 5;
			attack_delay = attack_delay - 3;
		}
	} while (cont == 1);
	return 0;
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>
#include <string>
#include "heap.h"
#include "poke327.h"
#include "character.h"
#include "io.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include<ncurses.h>
#include <algorithm>
#include <regex>

using namespace std;

class pokemon
{
    public:
        int id;
        string name;
        int species_id;
        int height;
        int weight;
        int base_xp;
        int order;
        int is_default;

    void clear()
    {
        id = -1;
        name = "";
        species_id = -1;
        height = -1;
        weight = -1;
        base_xp = -1;
        order = -1;
        is_default = -1;
    }

    void print()
    {
        cout << "id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Species id: " << species_id << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Base XP: " << base_xp << endl;
        cout << "Order: " << order << endl;
        cout << "Is Default: " << is_default << endl;
        cout << endl;
    }
};

class moves
{
    public:
        int id;
        string name;
        int generation_id;
        int type_id;
        int power;
        int pp;
        int accuracy;
        int priority;
        int target_id;
        int damage_class_id;
        int effect_id;
        int effect_chance;
        int contest_type_id;
        int contest_effect_id;
        int super_contest_effect_id;

    void clear()
    {
        id = -1;
        name = "";
        generation_id = -1;
        type_id = -1;
        power = -1;
        pp = -1;
        accuracy = -1;
        priority = -1;
        target_id = -1;
        damage_class_id = -1;
        effect_id = -1;
        effect_chance = -1;
        contest_type_id = -1;
        contest_effect_id = -1;
        super_contest_effect_id = -1;
    }

    void print()
    {
        cout << "id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Generation Id: " << generation_id << endl;
        cout << "Type Id: " << type_id << endl;
        cout << "Power: " << power << endl;
        cout << "PP: " << pp << endl;
        cout << "Accuracy: " << accuracy << endl;
        cout << "Priority: " << priority << endl;
        cout << "target_id: " << target_id << endl;
        cout << "damage_class_id: " << damage_class_id << endl;
        cout << "effect_id: " << effect_id << endl;
        cout << "effect_chance: " << effect_chance << endl;
        cout << "effect_chance: " << effect_chance << endl;
        cout << "contest_type_id: " << contest_type_id << endl;
        cout << "contest_effect_id: " << contest_effect_id << endl;
        cout << "super_contest_effect_id: " << super_contest_effect_id << endl;
        cout << endl;
    }
};

class pokemon_moves
{
    public:
        int pokemon_id;
        int version_group_id;
        int move_id;
        int pokemon_move_method_id;
        int level;
        int order;

    void clear()
    {
        pokemon_id = -1;
        version_group_id = -1;
        move_id = -1;
        pokemon_move_method_id = -1;
        level = -1;
        order = -1;
    }

    void print()
    {
        cout << "pokemon_id: " << pokemon_id << endl;
        cout << "version_group_id: " << version_group_id << endl;
        cout << "move_id: " << move_id << endl;
        cout << "pokemon_move_method_id: " << pokemon_move_method_id << endl;
        cout << "level: " << level << endl;
        cout << "order: " << order << endl;
        cout << endl;
    }
};

class pokemon_species
{
    public:
        int id;
        string name;
        int generation_id;
        int evolves_from_species_id;
        int evolution_chain_id;
        int color_id;
        int shape_id;
        int habit_id;
        int gender_rate;
        int capture_rate;
        int base_happiness;
        int is_baby;
        int hatch_counter;
        int has_gender_differences;
        int growth_rate_id;
        int forms_switchable;
        int is_legendary;
        int is_mythical;
        int order;
        int conquest_order;

    void clear()
    {
        id = -1;
        name = "";
        generation_id = -1;
        evolves_from_species_id = -1;
        evolution_chain_id = -1;
        color_id = -1;
        shape_id = -1;
        habit_id = -1;
        gender_rate = -1;
        capture_rate = -1;
        base_happiness = -1;
        is_baby = -1;
        hatch_counter = -1;
        has_gender_differences = -1;
        growth_rate_id = -1;
        forms_switchable = -1;
        is_legendary = -1;
        is_mythical = -1;
        order = -1;
        conquest_order = -1;
    }

    void print()
    {
        cout << "id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Generation Id: " << generation_id << endl;
        cout << "evolves_from_species_id: " << evolves_from_species_id << endl;
        cout << "evolution_chain_id: " << evolution_chain_id << endl;
        cout << "color_id: " << color_id << endl;
        cout << "shape_id: " << shape_id << endl;
        cout << "habit_id: " << habit_id << endl;
        cout << "gender_rate: " << gender_rate << endl;
        cout << "capture_rate: " << capture_rate << endl;
        cout << "base_happiness: " << base_happiness << endl;
        cout << "is_baby: " << is_baby << endl;
        cout << "hatch_counter: " << hatch_counter << endl;
        cout << "has_gender_differences: " << has_gender_differences << endl;
        cout << "growth_rate_id: " << growth_rate_id << endl;
        cout << "forms_switchable: " << forms_switchable << endl;
        cout << "is_legendary: " << is_legendary << endl;
        cout << "is_mythical: " << is_mythical << endl;
        cout << "order: " << order << endl;
        cout << "conquest_order: " << conquest_order << endl;
        cout << endl;
    }
};

class experience
{
    public:
        int growth_rate_id;
        int level;
        int experience;

    void clear()
    {
        growth_rate_id = -1;
        level = -1;
        experience = -1;
    }

    void print()
    {
        cout << "growth_rate_id: " << growth_rate_id << endl;
        cout << "level: " << level << endl;
        cout << "experience: " << experience << endl;
        cout << endl;
    }
};

class type_names
{
    public:
        int type_id;
        int local_language_id;
        string name;

    void clear()
    {
        type_id = -1;
        local_language_id = -1;
        name = "";
    }

    void print()
    {
        cout << "type_id: " << type_id << endl;
        cout << "local_language_id: " << local_language_id << endl;
        cout << "name: " << name << endl;
        cout << endl;
    }
};


typedef struct queue_node {
  int x, y;
  struct queue_node *next;
} queue_node_t;

world_t world;

pair_t all_dirs[8] = {
  { -1, -1 },
  { -1,  0 },
  { -1,  1 },
  {  0, -1 },
  {  0,  1 },
  {  1, -1 },
  {  1,  0 },
  {  1,  1 },
};

static int32_t path_cmp(const void *key, const void *with) {
  return ((path_t *) key)->cost - ((path_t *) with)->cost;
}

static int32_t edge_penalty(int8_t x, int8_t y)
{
  return (x == 1 || y == 1 || x == MAP_X - 2 || y == MAP_Y - 2) ? 2 : 1;
}

static void dijkstra_path(map_t *m, pair_t from, pair_t to)
{
  static path_t path[MAP_Y][MAP_X], *p;
  static uint32_t initialized = 0;
  heap_t h;
  uint32_t x, y;

  if (!initialized) {
    for (y = 0; y < MAP_Y; y++) {
      for (x = 0; x < MAP_X; x++) {
        path[y][x].pos[dim_y] = y;
        path[y][x].pos[dim_x] = x;
      }
    }
    initialized = 1;
  }
  
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      path[y][x].cost = INT_MAX;
    }
  }

  path[from[dim_y]][from[dim_x]].cost = 0;

  heap_init(&h, path_cmp, NULL);

  for (y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      path[y][x].hn = heap_insert(&h, &path[y][x]);
    }
  }

  while ((p = (path_t*)heap_remove_min(&h))) {
    p->hn = NULL;

    if ((p->pos[dim_y] == to[dim_y]) && p->pos[dim_x] == to[dim_x]) {
      for (x = to[dim_x], y = to[dim_y];
           (x != (uint32_t)from[dim_x]) || (y != (uint32_t)from[dim_y]);
           p = &path[y][x], x = p->from[dim_x], y = p->from[dim_y]) {
        mapxy(x, y) = ter_path;
        heightxy(x, y) = 0;
      }
      heap_delete(&h);
      return;
    }

    if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x], p->pos[dim_y] - 1)))) {
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x], p->pos[dim_y] - 1));
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
                                           [p->pos[dim_x]    ].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] - 1].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] - 1].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] + 1].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] + 1].hn);
    }
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1)))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1));
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x]    ].hn);
    }
  }
}

static int build_paths(map_t *m)
{
  pair_t from, to;

  /*  printf("%d %d %d %d\n", m->n, m->s, m->e, m->w);*/

  if (m->e != -1 && m->w != -1) {
    from[dim_x] = 1;
    to[dim_x] = MAP_X - 2;
    from[dim_y] = m->w;
    to[dim_y] = m->e;

    dijkstra_path(m, from, to);
  }

  if (m->n != -1 && m->s != -1) {
    from[dim_y] = 1;
    to[dim_y] = MAP_Y - 2;
    from[dim_x] = m->n;
    to[dim_x] = m->s;

    dijkstra_path(m, from, to);
  }

  if (m->e == -1) {
    if (m->s == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->w == -1) {
    if (m->s == -1) {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->n == -1) {
    if (m->e == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->s == -1) {
    if (m->e == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    }

    dijkstra_path(m, from, to);
  }

  return 0;
}

static int gaussian[5][5] = {
  {  1,  4,  7,  4,  1 },
  {  4, 16, 26, 16,  4 },
  {  7, 26, 41, 26,  7 },
  {  4, 16, 26, 16,  4 },
  {  1,  4,  7,  4,  1 }
};

static int smooth_height(map_t *m)
{
  int32_t i, x, y;
  int32_t s, t, p, q;
  queue_node_t *head, *tail, *tmp;
  /*  FILE *out;*/
  uint8_t height[MAP_Y][MAP_X];

  memset(&height, 0, sizeof (height));

  /* Seed with some values */
  for (i = 1; i < 255; i += 20) {
    do {
      x = rand() % MAP_X;
      y = rand() % MAP_Y;
    } while (height[y][x]);
    height[y][x] = i;
    if (i == 1) {
      head = tail = (queue_node_t*)malloc(sizeof (*tail));
    } else {
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
    }
    tail->next = NULL;
    tail->x = x;
    tail->y = y;
  }

  /*
  out = fopen("seeded.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&height, sizeof (height), 1, out);
  fclose(out);
  */
  
  /* Diffuse the vaules to fill the space */
  while (head) {
    x = head->x;
    y = head->y;
    i = height[y][x];

    if (x - 1 >= 0 && y - 1 >= 0 && !height[y - 1][x - 1]) {
      height[y - 1][x - 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y - 1;
    }
    if (x - 1 >= 0 && !height[y][x - 1]) {
      height[y][x - 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y;
    }
    if (x - 1 >= 0 && y + 1 < MAP_Y && !height[y + 1][x - 1]) {
      height[y + 1][x - 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y + 1;
    }
    if (y - 1 >= 0 && !height[y - 1][x]) {
      height[y - 1][x] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y - 1;
    }
    if (y + 1 < MAP_Y && !height[y + 1][x]) {
      height[y + 1][x] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y + 1;
    }
    if (x + 1 < MAP_X && y - 1 >= 0 && !height[y - 1][x + 1]) {
      height[y - 1][x + 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y - 1;
    }
    if (x + 1 < MAP_X && !height[y][x + 1]) {
      height[y][x + 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y;
    }
    if (x + 1 < MAP_X && y + 1 < MAP_Y && !height[y + 1][x + 1]) {
      height[y + 1][x + 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y + 1;
    }

    tmp = head;
    head = head->next;
    free(tmp);
  }

  /* And smooth it a bit with a gaussian convolution */
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      for (s = t = p = 0; p < 5; p++) {
        for (q = 0; q < 5; q++) {
          if (y + (p - 2) >= 0 && y + (p - 2) < MAP_Y &&
              x + (q - 2) >= 0 && x + (q - 2) < MAP_X) {
            s += gaussian[p][q];
            t += height[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
          }
        }
      }
      m->height[y][x] = t / s;
    }
  }
  /* Let's do it again, until it's smooth like Kenny G. */
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      for (s = t = p = 0; p < 5; p++) {
        for (q = 0; q < 5; q++) {
          if (y + (p - 2) >= 0 && y + (p - 2) < MAP_Y &&
              x + (q - 2) >= 0 && x + (q - 2) < MAP_X) {
            s += gaussian[p][q];
            t += height[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
          }
        }
      }
      m->height[y][x] = t / s;
    }
  }

  /*
  out = fopen("diffused.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&height, sizeof (height), 1, out);
  fclose(out);
  out = fopen("smoothed.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->height, sizeof (m->height), 1, out);
  fclose(out);
  */

  return 0;
}

static void find_building_location(map_t *m, pair_t p)
{
  do {
    p[dim_x] = rand() % (MAP_X - 5) + 3;
    p[dim_y] = rand() % (MAP_Y - 10) + 5;

    if ((((mapxy(p[dim_x] - 1, p[dim_y]    ) == ter_path)     &&
          (mapxy(p[dim_x] - 1, p[dim_y] + 1) == ter_path))    ||
         ((mapxy(p[dim_x] + 2, p[dim_y]    ) == ter_path)     &&
          (mapxy(p[dim_x] + 2, p[dim_y] + 1) == ter_path))    ||
         ((mapxy(p[dim_x]    , p[dim_y] - 1) == ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] - 1) == ter_path))    ||
         ((mapxy(p[dim_x]    , p[dim_y] + 2) == ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 2) == ter_path)))   &&
        (((mapxy(p[dim_x]    , p[dim_y]    ) != ter_mart)     &&
          (mapxy(p[dim_x]    , p[dim_y]    ) != ter_center)   &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_mart)     &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_center)   &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_mart)     &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_center)   &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_mart)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_center))) &&
        (((mapxy(p[dim_x]    , p[dim_y]    ) != ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_path)     &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_path)))) {
          break;
    }
  } while (1);
}

static int place_pokemart(map_t *m)
{
  pair_t p;

  find_building_location(m, p);

  mapxy(p[dim_x]    , p[dim_y]    ) = ter_mart;
  mapxy(p[dim_x] + 1, p[dim_y]    ) = ter_mart;
  mapxy(p[dim_x]    , p[dim_y] + 1) = ter_mart;
  mapxy(p[dim_x] + 1, p[dim_y] + 1) = ter_mart;

  return 0;
}

static int place_center(map_t *m)
{  pair_t p;

  find_building_location(m, p);

  mapxy(p[dim_x]    , p[dim_y]    ) = ter_center;
  mapxy(p[dim_x] + 1, p[dim_y]    ) = ter_center;
  mapxy(p[dim_x]    , p[dim_y] + 1) = ter_center;
  mapxy(p[dim_x] + 1, p[dim_y] + 1) = ter_center;

  return 0;
}

static int map_terrain(map_t *m, int8_t n, int8_t s, int8_t e, int8_t w)
{
  int32_t i, x, y;
  queue_node_t *head, *tail, *tmp;
  //  FILE *out;
  int num_grass, num_clearing, num_mountain, num_forest, num_total;
  terrain_type_t type;
  int added_current = 0;
  
  num_grass = rand() % 4 + 2;
  num_clearing = rand() % 4 + 2;
  num_mountain = rand() % 2 + 1;
  num_forest = rand() % 2 + 1;
  num_total = num_grass + num_clearing + num_mountain + num_forest;

  memset(&m->map, 0, sizeof (m->map));

  /* Seed with some values */
  for (i = 0; i < num_total; i++) {
    do {
      x = rand() % MAP_X;
      y = rand() % MAP_Y;
    } while (m->map[y][x]);
    if (i == 0) {
      type = ter_grass;
    } else if (i == num_grass) {
      type = ter_clearing;
    } else if (i == num_grass + num_clearing) {
      type = ter_mountain;
    } else if (i == num_grass + num_clearing + num_mountain) {
      type = ter_forest;
    }
    m->map[y][x] = type;
    if (i == 0) {
      head = tail = (queue_node_t*)malloc(sizeof (*tail));
    } else {
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
    }
    tail->next = NULL;
    tail->x = x;
    tail->y = y;
  }

  /*
  out = fopen("seeded.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->map, sizeof (m->map), 1, out);
  fclose(out);
  */

  /* Diffuse the vaules to fill the space */
  while (head) {
    x = head->x;
    y = head->y;
    i = m->map[y][x];
    
    if (x - 1 >= 0 && !m->map[y][x - 1]) {
      if ((rand() % 100) < 80) {
        m->map[y][x - 1] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x - 1;
        tail->y = y;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (y - 1 >= 0 && !m->map[y - 1][x]) {
      if ((rand() % 100) < 20) {
        m->map[y - 1][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y - 1;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (y + 1 < MAP_Y && !m->map[y + 1][x]) {
      if ((rand() % 100) < 20) {
        m->map[y + 1][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y + 1;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (x + 1 < MAP_X && !m->map[y][x + 1]) {
      if ((rand() % 100) < 80) {
        m->map[y][x + 1] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x + 1;
        tail->y = y;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    added_current = 0;
    tmp = head;
    head = head->next;
    free(tmp);
  }

  /*
  out = fopen("diffused.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->map, sizeof (m->map), 1, out);
  fclose(out);
  */
  
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (y == 0 || y == MAP_Y - 1 ||
          x == 0 || x == MAP_X - 1) {
        mapxy(x, y) = ter_boulder;
      }
    }
  }

  m->n = n;
  m->s = s;
  m->e = e;
  m->w = w;

  if (n != -1) {
    mapxy(n,         0        ) = ter_exit;
    mapxy(n,         1        ) = ter_path;
  }
  if (s != -1) {
    mapxy(s,         MAP_Y - 1) = ter_exit;
    mapxy(s,         MAP_Y - 2) = ter_path;
  }
  if (w != -1) {
    mapxy(0,         w        ) = ter_exit;
    mapxy(1,         w        ) = ter_path;
  }
  if (e != -1) {
    mapxy(MAP_X - 1, e        ) = ter_exit;
    mapxy(MAP_X - 2, e        ) = ter_path;
  }

  return 0;
}

static int place_boulders(map_t *m)
{
  int i;
  int x, y;

  for (i = 0; i < MIN_BOULDERS || rand() % 100 < BOULDER_PROB; i++) {
    y = rand() % (MAP_Y - 2) + 1;
    x = rand() % (MAP_X - 2) + 1;
    if (m->map[y][x] != ter_forest && m->map[y][x] != ter_path) {
      m->map[y][x] = ter_boulder;
    }
  }

  return 0;
}

static int place_trees(map_t *m)
{
  int i;
  int x, y;
  
  for (i = 0; i < MIN_TREES || rand() % 100 < TREE_PROB; i++) {
    y = rand() % (MAP_Y - 2) + 1;
    x = rand() % (MAP_X - 2) + 1;
    if (m->map[y][x] != ter_mountain && m->map[y][x] != ter_path) {
      m->map[y][x] = ter_tree;
    }
  }

  return 0;
}

void rand_pos(pair_t pos)
{
  pos[dim_x] = (rand() % (MAP_X - 2)) + 1;
  pos[dim_y] = (rand() % (MAP_Y - 2)) + 1;
}

void new_hiker()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.hiker_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t*)malloc(sizeof (*c));
  c->npc = (npc_t*)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_hiker;
  c->npc->mtype = move_hiker;
  c->npc->dir[dim_x] = 0;
  c->npc->dir[dim_y] = 0;
  c->npc->defeated = 0;
  c->pc = NULL;
  c->symbol = 'h';
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);

  //  printf("Hiker at %d,%d\n", pos[dim_x], pos[dim_y]);
}

void new_rival()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.rival_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.rival_dist[pos[dim_y]][pos[dim_x]] < 0        ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t*)malloc(sizeof (*c));
  c->npc = (npc_t*)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_rival;
  c->npc->mtype = move_rival;
  c->npc->dir[dim_x] = 0;
  c->npc->dir[dim_y] = 0;
  c->npc->defeated = 0;
  c->pc = NULL;
  c->symbol = 'r';
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);
}

void new_char_other()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.rival_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.rival_dist[pos[dim_y]][pos[dim_x]] < 0        ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t*)malloc(sizeof (*c));
  c->npc = (npc_t*)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_other;
  switch (rand() % 4) {
  case 0:
    c->npc->mtype = move_pace;
    c->symbol = 'p';
    break;
  case 1:
    c->npc->mtype = move_wander;
    c->symbol = 'w';
    break;
  case 2:
    c->npc->mtype = move_sentry;
    c->symbol = 's';
    break;
  case 3:
    c->npc->mtype = move_walk;
    c->symbol = 'n';
    break;
  }
  rand_dir(c->npc->dir);
  c->npc->defeated = 0;
  c->pc = NULL;
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);
}

void place_characters()
{
  world.cur_map->num_trainers = 2;

  //Always place a hiker and a rival, then place a random number of others
  new_hiker();
  new_rival();
  do {
    //higher probability of non- hikers and rivals
    switch(rand() % 10) {
    case 0:
      new_hiker();
      break;
    case 1:
     new_rival();
      break;
    default:
      new_char_other();
      break;
    }
  } while (++world.cur_map->num_trainers < MIN_TRAINERS ||
           ((rand() % 100) < ADD_TRAINER_PROB));
}

void init_pc()
{
  int x, y;

  do {
    x = rand() % (MAP_X - 2) + 1;
    y = rand() % (MAP_Y - 2) + 1;
  } while (world.cur_map->map[y][x] != ter_path);

  world.pc.pos[dim_x] = x;
  world.pc.pos[dim_y] = y;
  world.pc.symbol = '@';
  world.pc.pc = (pc_t*)malloc(sizeof (*world.pc.pc));
  world.pc.npc = NULL;

  world.cur_map->cmap[y][x] = &world.pc;
  world.pc.next_turn = 0;

  heap_insert(&world.cur_map->turn, &world.pc);
}

void place_pc()
{
  character_t *c;

  if (world.pc.pos[dim_x] == 1) {
    world.pc.pos[dim_x] = MAP_X - 2;
  } else if (world.pc.pos[dim_x] == MAP_X - 2) {
    world.pc.pos[dim_x] = 1;
  } else if (world.pc.pos[dim_y] == 1) {
    world.pc.pos[dim_y] = MAP_Y - 2;
  } else if (world.pc.pos[dim_y] == MAP_Y - 2) {
    world.pc.pos[dim_y] = 1;
  }

  world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = &world.pc;

  if ((c = (character_t*)heap_peek_min(&world.cur_map->turn))) {
    world.pc.next_turn = c->next_turn;
  } else {
    world.pc.next_turn = 0;
  }
}

// New map expects cur_idx to refer to the index to be generated.  If that
// map has already been generated then the only thing this does is set
// cur_map.
int new_map(int teleport)
{
  int d, p;
  int e, w, n, s;
  int x, y;
  
  if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]]) {
    world.cur_map = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]];
    place_pc();

    return 0;
  }

  world.cur_map                                             =
    world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]] =
    (map_t*)malloc(sizeof (*world.cur_map));

  smooth_height(world.cur_map);
  
  if (!world.cur_idx[dim_y]) {
    n = -1;
  } else if (world.world[world.cur_idx[dim_y] - 1][world.cur_idx[dim_x]]) {
    n = world.world[world.cur_idx[dim_y] - 1][world.cur_idx[dim_x]]->s;
  } else {
    n = 3 + rand() % (MAP_X - 6);
  }
  if (world.cur_idx[dim_y] == WORLD_SIZE - 1) {
    s = -1;
  } else if (world.world[world.cur_idx[dim_y] + 1][world.cur_idx[dim_x]]) {
    s = world.world[world.cur_idx[dim_y] + 1][world.cur_idx[dim_x]]->n;
  } else  {
    s = 3 + rand() % (MAP_X - 6);
  }
  if (!world.cur_idx[dim_x]) {
    w = -1;
  } else if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] - 1]) {
    w = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] - 1]->e;
  } else {
    w = 3 + rand() % (MAP_Y - 6);
  }
  if (world.cur_idx[dim_x] == WORLD_SIZE - 1) {
    e = -1;
  } else if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] + 1]) {
    e = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] + 1]->w;
  } else {
    e = 3 + rand() % (MAP_Y - 6);
  }
  
  map_terrain(world.cur_map, n, s, e, w);
     
  place_boulders(world.cur_map);
  place_trees(world.cur_map);
  build_paths(world.cur_map);
  d = (abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)) +
       abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)));
  p = d > 200 ? 5 : (50 - ((45 * d) / 200));
  //  printf("d=%d, p=%d\n", d, p);
  if ((rand() % 100) < p || !d) {
    place_pokemart(world.cur_map);
  }
  if ((rand() % 100) < p || !d) {
    place_center(world.cur_map);
  }

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      world.cur_map->cmap[y][x] = NULL;
    }
  }

  heap_init(&world.cur_map->turn, cmp_char_turns, delete_character);

  if ((world.cur_idx[dim_x] == WORLD_SIZE / 2) &&
      (world.cur_idx[dim_y] == WORLD_SIZE / 2)) {
    init_pc();
  } else {
    place_pc();
  }

  pathfind(world.cur_map);
  if (teleport) {
    do {
      world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = NULL;
      world.pc.pos[dim_x] = rand_range(1, MAP_X - 2);
      world.pc.pos[dim_y] = rand_range(1, MAP_Y - 2);
    } while (world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ||
             (move_cost[char_pc][world.cur_map->map[world.pc.pos[dim_y]]
                                                   [world.pc.pos[dim_x]]] ==
              INT_MAX)                                                      ||
             world.rival_dist[world.pc.pos[dim_y]][world.pc.pos[dim_x]] < 0);
    world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = &world.pc;
    pathfind(world.cur_map);
  }
  
  place_characters();

  return 0;
}

/*
static void print_map()
{
  int x, y;
  int default_reached = 0;
  printf("\n\n\n");
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.cur_map->cmap[y][x]) {
        putchar(world.cur_map->cmap[y][x]->symbol);
      } else {
        switch (world.cur_map->map[y][x]) {
        case ter_boulder:
        case ter_mountain:
          putchar('%');
          break;
        case ter_tree:
        case ter_forest:
          putchar('^');
          break;
        case ter_path:
          putchar('#');
          break;
        case ter_mart:
          putchar('M');
          break;
        case ter_center:
          putchar('C');
          break;
        case ter_grass:
          putchar(':');
          break;
        case ter_clearing:
          putchar('.');
          break;
        default:
          default_reached = 1;
          break;
        }
      }
    }
    putchar('\n');
  }
  if (default_reached) {
    fprintf(stderr, "Default reached in %s\n", __FUNCTION__);
  }
}
*/

// The world is global because of its size, so init_world is parameterless
void init_world()
{
  world.quit = 0;
  world.cur_idx[dim_x] = world.cur_idx[dim_y] = WORLD_SIZE / 2;
  new_map(0);
}

void delete_world()
{
  int x, y;

  //Only correct because current game never leaves the initial map
  //Need to iterate over all maps in 1.05+
  heap_delete(&world.cur_map->turn);

  for (y = 0; y < WORLD_SIZE; y++) {
    for (x = 0; x < WORLD_SIZE; x++) {
      if (world.world[y][x]) {
        free(world.world[y][x]);
        world.world[y][x] = NULL;
      }
    }
  }
}

void print_hiker_dist()
{
  int x, y;

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.hiker_dist[y][x] == INT_MAX) {
        printf("   ");
      } else {
        printf(" %5d", world.hiker_dist[y][x]);
      }
    }
    printf("\n");
  }
}

void print_rival_dist()
{
  int x, y;

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.rival_dist[y][x] == INT_MAX || world.rival_dist[y][x] < 0) {
        printf("   ");
      } else {
        printf(" %02d", world.rival_dist[y][x] % 100);
      }
    }
    printf("\n");
  }
}

void leave_map(pair_t d)
{
  if (d[dim_x] == 0) {
    world.cur_idx[dim_x]--;
  } else if (d[dim_y] == 0) {
    world.cur_idx[dim_y]--;
  } else if (d[dim_x] == MAP_X - 1) {
    world.cur_idx[dim_x]++;
  } else {
    world.cur_idx[dim_y]++;
  }
  new_map(0);
}

void game_loop()
{
  character_t *c;
  pair_t d;
  
  while (!world.quit) {
    c = (character_t*)heap_remove_min(&world.cur_map->turn);

    move_func[c->npc ? c->npc->mtype : move_pc](c, d);

    world.cur_map->cmap[c->pos[dim_y]][c->pos[dim_x]] = NULL;
    if (c->pc && (d[dim_x] == 0 || d[dim_x] == MAP_X - 1 ||
                  d[dim_y] == 0 || d[dim_y] == MAP_Y - 1)) {
      leave_map(d);
      d[dim_x] = c->pos[dim_x];
      d[dim_y] = c->pos[dim_y];
    }
    world.cur_map->cmap[d[dim_y]][d[dim_x]] = c;

    if (c->pc) {
      // Performance bug - pathfinding runs twice after generating a new map
      pathfind(world.cur_map);
    }

    c->next_turn += move_cost[c->npc ? c->npc->ctype : char_pc]
                             [world.cur_map->map[d[dim_y]][d[dim_x]]];

    c->pos[dim_y] = d[dim_y];
    c->pos[dim_x] = d[dim_x];

    heap_insert(&world.cur_map->turn, c);
  }
}


int main(int argc, char *argv[])
{
    string path_online = "/share/cs327/";
    string home = getenv("HOME");
    string path_local = "";
    path_local = home + "/.poke327/";
    string csv_home = "pokedex/pokedex/data/csv/";
    ifstream f("");
    string path;
    string file_name;


    path_online += csv_home;
    path_local += csv_home;

    cout << "Enter file you want to parse excluding the extension: ";
    cin >> file_name;

    if(file_name ==""){
        cout << "Invalid input" << endl;
        return -1; 
    } else{
        path_online = path_online + file_name + ".csv";
        path_local = path_local + file_name + ".csv";

        ifstream f(path_online);
        if(!f.good()){
            ifstream f(path_local);
            if(!f.good()){
                cout << "File not found" << endl;
                return -1;
            } else{
                path = path_local;
            }
        } else{
            path = path_online;
        }
    }
    f.open(path);

    if(file_name == "moves"){
        vector<moves> items;
        string line, word;
        moves p;
        int index;
        getline(f, line); 
        while(getline(f, line)){
            index = 0;
            p.clear();
            stringstream str(line);

            while(getline(str, word, ',')){
                switch(index){
                    case 0:
                        if(word != ""){
                            p.id = stoi(word);
                        }
                        break;
                    case 1:
                        if(word != ""){
                            p.name = word;
                        }
                        break;
                    case 2:
                        if(word != ""){
                            p.generation_id = stoi(word);
                        }
                        break;
                    case 3:
                        if(word != ""){
                            p.type_id = stoi(word);
                        }
                        break;
                    case 4:
                        if(word != ""){
                            p.power = stoi(word);
                        }
                        break;
                    case 5:
                        if(word != ""){
                            p.pp = stoi(word);
                        }
                        break;
                    case 6:
                        if(word != ""){
                            p.accuracy = stoi(word);
                        }
                        break;
                    case 7:
                        if(word != ""){
                            p.priority = stoi(word);
                        }
                        break;
                    case 8:
                        if(word != ""){
                            p.target_id = stoi(word);
                        }
                        break;
                    case 9:
                        if(word != ""){
                            p.damage_class_id = stoi(word);
                        }
                        break;
                    case 10:
                        if(word != ""){
                            p.effect_id = stoi(word);
                        }
                        break;
                    case 11:
                        if(word != ""){
                            p.effect_chance = stoi(word);
                        }
                        break;
                    case 12:
                        if(word != ""){
                            p.contest_type_id = stoi(word);
                        }
                        break;
                    case 13:
                        if(word != ""){
                            p.contest_effect_id = stoi(word);
                        }
                        break;
                    case 14:
                        if(word != ""){
                            p.super_contest_effect_id = stoi(word);
                        }
                        break;
                    default:
                        break;
                }
                index++;
            }
            items.push_back(p);
            p.print();
        }
    } else if(file_name == "pokemon"){
        vector<pokemon> items;
        string line, word;
        pokemon p;
        int index;
        getline(f, line); 
        while(getline(f, line)){
            index = 0;
            p.clear();
            stringstream str(line);

            while(getline(str, word, ',')){
                switch(index){
                    case 0:
                        if(word != ""){
                            p.id = stoi(word);
                        }
                        break;
                    case 1:
                        if(word != ""){
                            p.name = word;
                        }
                        break;
                    case 2:
                        if(word != ""){
                            p.species_id = stoi(word);
                        }
                        break;
                    case 3:
                        if(word != ""){
                            p.height = stoi(word);
                        }
                        break;
                    case 4:
                        if(word != ""){
                            p.weight = stoi(word);
                        }
                        break;
                    case 5:
                        if(word != ""){
                            p.base_xp = stoi(word);
                        }
                        break;
                    case 6:
                        if(word != ""){
                            p.order = stoi(word);
                        }
                        break;
                    case 7:
                        if(word != ""){
                            p.is_default = stoi(word);
                        }
                        break;
                    default:
                        break;
                }
                index++;

            }
            items.push_back(p);
            p.print();

        }
    } else if(file_name == "pokemon_moves"){
        vector<pokemon_moves> items;
        string line, word;
        pokemon_moves p;
        int index;
        getline(f, line); 
        while(getline(f, line)){
            index = 0;
            p.clear();
            stringstream str(line);

            while(getline(str, word, ',')){
                switch(index){
                    case 0:
                        if(word != ""){
                            p.pokemon_id = stoi(word);
                        }
                        break;
                    case 1:
                        if(word != ""){
                            p.version_group_id = stoi(word);
                        }
                        break;
                    case 2:
                        if(word != ""){
                            p.move_id = stoi(word);
                        }
                        break;
                    case 3:
                        if(word != ""){
                            p.pokemon_move_method_id = stoi(word);
                        }
                        break;
                    case 4:
                        if(word != ""){
                            p.level = stoi(word);
                        }
                        break;
                    case 5:
                        if(word != ""){
                            p.order = stoi(word);
                        }
                        break;
                    default:
                        break;
                }
                index++;

            }
            items.push_back(p);
            p.print();

        }
    } else if(file_name == "pokemon_species") {
        vector<pokemon_species> items;
        string line, word;
        pokemon_species p;
        int index;
        getline(f, line); 
        while(getline(f, line)){
            index = 0;
            p.clear();
            stringstream str(line);

            while(getline(str, word, ',')){
                switch(index){
                    case 0:
                        if(word != ""){
                            p.id = stoi(word);
                        }
                        break;
                    case 1:
                        if(word != ""){
                            p.name = word;
                        }
                        break;
                    case 2:
                        if(word != ""){
                            p.generation_id = stoi(word);
                        }
                        break;
                    case 3:
                        if(word != ""){
                            p.evolves_from_species_id = stoi(word);
                        }
                        break;
                    case 4:
                        if(word != ""){
                            p.evolution_chain_id = stoi(word);
                        }
                        break;
                    case 5:
                        if(word != ""){
                            p.color_id = stoi(word);
                        }
                        break;
                    case 6:
                        if(word != ""){
                            p.shape_id = stoi(word);
                        }
                        break;
                    case 7:
                        if(word != ""){
                            p.habit_id = stoi(word);
                        }
                        break;
                    case 8:
                        if(word != ""){
                            p.gender_rate = stoi(word);
                        }
                        break;
                    case 9:
                        if(word != ""){
                            p.capture_rate = stoi(word);
                        }
                        break;
                    case 10:
                        if(word != ""){
                            p.base_happiness = stoi(word);
                        }
                        break;
                    case 11:
                        if(word != ""){
                            p.is_baby = stoi(word);
                        }
                        break;
                    case 12:
                        if(word != ""){
                            p.hatch_counter = stoi(word);
                        }
                        break;
                    case 13:
                        if(word != ""){
                            p.has_gender_differences = stoi(word);
                        }
                        break;
                    case 14:
                        if(word != ""){
                            p.growth_rate_id = stoi(word);
                        }
                        break;
                    case 15:
                        if(word != ""){
                            p.forms_switchable = stoi(word);
                        }
                        break;
                    case 16:
                        if(word != ""){
                            p.is_legendary = stoi(word);
                        }
                        break;
                    case 17:
                        if(word != ""){
                            p.is_mythical = stoi(word);
                        }
                        break;
                    case 18:
                        if(word != ""){
                            p.order = stoi(word);
                        }
                        break;
                    case 19:
                        if(word != ""){
                            p.conquest_order = stoi(word);
                        }
                        break;
                    default:
                        break;
                }
                index++;

            }
            items.push_back(p);
            p.print();

        }
    } else if(file_name == "experience") {
        vector<experience> items;
        string line, word;
        experience p;
        int index;
        getline(f, line); 
        while(getline(f, line)){
            index = 0;
            p.clear();
            stringstream str(line);

            while(getline(str, word, ',')){
                switch(index){
                    case 0:
                        if(word != ""){
                            p.growth_rate_id = stoi(word);
                        }
                        break;
                    case 1:
                        if(word != ""){
                            p.level = stoi(word);
                        }
                        break;
                    case 2:
                        if(word != ""){
                            p.experience = stoi(word);
                        }
                        break;
                    default:
                        break;
                }
                index++;
            }
            items.push_back(p);
            p.print();
        }
    } else if(file_name == "type_names") {
        vector<type_names> items;
        string line, word;
        type_names p;
        int index;
        getline(f, line); 
        while(getline(f, line)){
            index = 0;
            p.clear();
            stringstream str(line);

            while(getline(str, word, ',')){
                switch(index){
                    case 0:
                        if(word != ""){
                            p.type_id = stoi(word);
                        }
                        break;
                    case 1:
                        if(word != ""){
                            p.local_language_id = stoi(word);
                        }
                        break;
                    case 2:
                        if(word != ""){
                            p.name = word;
                        }
                        break;
                    default:
                        break;
                }
                index++;
            }
            items.push_back(p);
            p.print();
        }
    } else{
        cout << "Inviled File" << endl;
    }
  // struct timeval tv;
  // uint32_t seed;
  // //  char c;
  // //  int x, y;

  // if (argc == 2) {
  //   seed = atoi(argv[1]);
  // } else {
  //   gettimeofday(&tv, NULL);
  //   seed = (tv.tv_usec ^ (tv.tv_sec << 20)) & 0xffffffff;
  // }


  // printf("Using seed: %u\n", seed);
  // srand(seed);

  // io_init_terminal();
  
  // init_world();

  /* print_hiker_dist(); */
  
  /*
  do {
    print_map();  
    printf("Current position is %d%cx%d%c (%d,%d).  "
           "Enter command: ",
           abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_x] - (WORLD_SIZE / 2) >= 0 ? 'E' : 'W',
           abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2) <= 0 ? 'N' : 'S',
           world.cur_idx[dim_x] - (WORLD_SIZE / 2),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2));
    scanf(" %c", &c);
    switch (c) {
    case 'n':
      if (world.cur_idx[dim_y]) {
        world.cur_idx[dim_y]--;
        new_map();
      }
      break;
    case 's':
      if (world.cur_idx[dim_y] < WORLD_SIZE - 1) {
        world.cur_idx[dim_y]++;
        new_map();
      }
      break;
    case 'e':
      if (world.cur_idx[dim_x] < WORLD_SIZE - 1) {
        world.cur_idx[dim_x]++;
        new_map();
      }
      break;
    case 'w':
      if (world.cur_idx[dim_x]) {
        world.cur_idx[dim_x]--;
        new_map();
      }
      break;
     case 'q':
      break;
    case 'f':
      scanf(" %d %d", &x, &y);
      if (x >= -(WORLD_SIZE / 2) && x <= WORLD_SIZE / 2 &&
          y >= -(WORLD_SIZE / 2) && y <= WORLD_SIZE / 2) {
        world.cur_idx[dim_x] = x + (WORLD_SIZE / 2);
        world.cur_idx[dim_y] = y + (WORLD_SIZE / 2);
        new_map();
      }
      break;
    case '?':
    case 'h':
      printf("Move with 'e'ast, 'w'est, 'n'orth, 's'outh or 'f'ly x y.\n"
             "Quit with 'q'.  '?' and 'h' print this help message.\n");
      break;
    default:
      fprintf(stderr, "%c: Invalid input.  Enter '?' for help.\n", c);
      break;
    }
  } while (c != 'q');
  */

  // game_loop();
  
  // delete_world();

  // io_reset_terminal();
  
  return 0;
}
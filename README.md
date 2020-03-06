# EASY CREATE PROJET
Suite aux exercices proposés par la lecture du livre "Initiation à l'algorithmique et à la programmation en C" j'avais besoin d'un programme en C qui me créer rapidement l'architecture d'un projet.

# Utilisation 
L'utilisaton du programme est la suivante :
```bash
./create_project <name_output_project>
```
Exemple :
```bash
/create_project exemple
```

# L'architecture lors de l'execution du programme
Avec l'exemple de la commande ci-dessus (cf exemple) l'architecture du projet crée sera la suivante :
```bash
.
├── create_project
└── exemple
    └── simple_program
        ├── Makefile
        └── src
            └── main.c

3 directories, 3 files
```

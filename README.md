<p align="center">
  <img src="./ressources/banner.gif" alt="Rush02 Banner" />
</p>

## Sujet

programmer `rush-02`, capable de convertir un **nombre entier positif** en **toutes lettres**, en s’appuyant sur un dictionnaire texte

---

## Exemple d’utilisation

```bash
$> ./rush-02 42
forty two

$> ./rush-02 100000
one hundred thousand

$> ./rush-02 custom.dict 20
twenty (ou autre selon le dictionnaire)
```

---

## Arguments

Le programme peut prendre :

- 1 argument : le **nombre** à convertir.
- 2 arguments : un **fichier dictionnaire personnalisé** + le nombre à convertir.

---

## Erreurs à gérer

- Nombre non valide (lettres, flottants, négatif, vide...) → `Error\n`
- Dictionnaire invalide ou incomplet → `Dict Error\n`

---

## Format du dictionnaire

```
<number>[espaces] : [espaces]<texte>
```

exemple :
```
0 : zero
100 : one hundred
42 : forty two
```

- Les lignes peuvent être dans n'importe quel ordre
- Il peut y avoir des lignes vides
- Les espaces autour du `:` ou du texte doivent être ignorés (`trim`)
- Le fichier doit contenir **au minimum toutes les clés de base nécessaires**

---

## Structure du projet

```
ex00/
├── main.c                → le main
├── parser.c/.h           → lit et parse le dictionnaire
├── dict_utils.c/.h       → fonctions de recherche dans le dictionnaire
├── number_to_words.c/.h  → convertit un nombre en lettres
├── string_utils.c/.h     → fonctions utiles et déjà codées (strlen, strcmp, etc.)
├── Makefile              → compilation
└── README.md             → moi
```

---

## Compilation

```bash
make
```

Le programme est compilé avec : `cc -Wall -Wextra -Werror`

---

## Bonus

- Ajouter les mots de liaison : `and`, `-`, `,`
- Support d'autres langues avec un dictionnaire traduit
- Lire depuis l’entrée standard si l’argument est `-` :
  ```bash
  ./rush-02 -
  42
  forty two
  ```

## Contributors:
>[Derhen David](https://profile.intra.42.fr/users/dedavid) | 
>[Hoël Keromnes](https://profile.intra.42.fr/users/hkeromne) | 
>[Julien Brousse](https://profile-v3.intra.42.fr/users/jubrouss)


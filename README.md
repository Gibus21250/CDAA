## Présentation

Projet universitaire de 3eme année pour le module Conception et Développement Avancé d'Application. (CDAA)

Ce projet a pour but de proposer une application de gestion de contact pour des entreprises, permettant aux utilisateur de
créer des fiches de contact, assigner des intéractions horodatées, ainsi que des tâches.

Codé en C++, et à l'aide de Qt.

Les données sont sauvegardé dans une base de donnée SQlite composée de 3 tables:
- Contact(__IdC__, nom, prenom, entreprise, email, tel, dateCreation, dateModification, photo)
- Interaction(__IdI__, Contenu, date, _IdC_)
- Tache(__IdT__, Contenu, dateAFaire, _IdI_)

Vous pouvez initialiser un jeu de donnée de test en executant le script `createTable.sql`

/!\ *Les images ne seront pas affichées, il faudra modifier le contact et reselectionner d'autre images, ou celles disponible le dossier source `image`* /!\

Vous pouvez exporter toutes les données sous format JSON depuis l'application, en cliquant sur Acceuil -> Exporter -> JSON

## **Comment utiliser**

### Windows 10/11:
Le programme est déjà compilé et pret à être utilisé dans le dossier Windows x64.
L'installeur est aussi téléchargeable dans la rebrique Release sur la page Github.

## Compiler soi-même

### Manuellement:

Prerequis: [qmake](https://www.qt.io/download) et [make](https://www.gnu.org/software/make/) et un compilateur c++

```
cd src
    qmake 
    make (relase | debug)
```

Le resultat de la compilation sera dans build-Projet-***-Release|Debug\n
Allez dans le dossier correspondant, puis executé l'executable.\n
Attention: Si vous êtes sur windows vous aurez besoin de *windeployqt.exe* (Qui se situe dans le dossier bin de votre istallation de Qt) qui ajoutera toutes les librairies dynamiques nécessaires pour le programme. [source](https://doc.qt.io/Qt-5/windows-deployment.html)

### Avec QtCreator
Dans QtCreator, importez le fichier Projet.pro situé dans le dossier src.\n
Ou, double cliquez directement sur le fichier Projet.pro.

## Informations

### Si l'application s'ouvre sans données:
Il faut que vous chargiez une base de données conforme, dans l'application allez dans Accueil -> Charger -> depuis BDD
puis choisissez une fichier *.sqlite*.

Un fichier *.sqlite* avec un jeu de donnée est déjà présent dans le dossier racine ``gestion.sqlite``.\n
Vous pouvez aussi générer les tables sur votre base de donnée à l'aide sur script ``createTable.sql`` avec quelques données.

### Si les contacts n'ont pas de photo de profil:

Deux solutions:
- Placer une copie du dossier ``src/images/`` dans le même dossier que l'executable.
- Recharger les images:
-- De nouvelles images directement.
-- Recharger les images du dossier ``src/images/``.

## Documentation

Une explication de l'utilisation de l'interface est disponible dans le fichier *rapport.pdf*.

Pour compiler une documentation complète du projet, il vous suffit d'executer la la commande ``doxygen Doxyfile``


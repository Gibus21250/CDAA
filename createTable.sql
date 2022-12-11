-- SQLite
DROP TABLE IF EXISTS Contact;
DROP TABLE IF EXISTS Interaction;
DROP TABLE IF EXISTS Tache;

PRAGMA foreign_keys = ON;

CREATE TABLE Contact 
(
    IdC INTEGER PRIMARY KEY, -- Remplace le ROWID de SQLite
    nom VARCHAR NOT NULL,
    prenom VARCHAR NOT NULL,
    entreprise VARCHAR,
    email VARCHAR NOT NULL,
    tel VARCHAR,
    dateCreation DATE NOT NULL,
    dateModification DATE,
    uriPhoto VARCHAR
);

CREATE TABLE Interaction 
(
    IdI INTEGER PRIMARY KEY,
    Contenu VARCHAR,
    dateCreation DATE,
    IdC INTEGER,

    FOREIGN KEY (IdC)
        REFERENCES Contact(IdC)
        ON DELETE CASCADE
);

CREATE TABLE Tache 
(
    IdT INTEGER PRIMARY KEY,
    Contenu VARCHAR,
    dateAFaire DATE,
    IdI INTEGER NOT NULL,

    FOREIGN KEY(IdI)
        REFERENCES Interaction(IdI)
        ON DELETE CASCADE
);

INSERT INTO Contact VALUES
(NULL, "Mortier", "Marie", "none", "m.m@gmail.com", "0607080910", "2022-11-12", "2022-11-12", NULL),
(NULL, "Jacquinet", "Nathan", "none", "n.j@gmail.com", "1090807060", "2022-12-08", "2022-12-08", NULL);

INSERT INTO Interaction VALUES (NULL, "Continuer SR", DATE('now'), 1); 

PRAGMA foreign_keys;
PRAGMA foreign_keys = ON;

-- PRAGMA foreign_keys = ON;DELETE FROM Contact WHERE IdC = 1;
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
    photo VARCHAR
);

CREATE TABLE Interaction 
(
    IdI INTEGER PRIMARY KEY,
    Contenu VARCHAR,
    date DATE,
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

--UPDATE Contact SET nom = 'test', prenom = 'wesh', dateModification = DATE('now') WHERE IdC = 15;

INSERT INTO Contact VALUES
(NULL, "Mortier", "Marie", "none", "marie.mortier@gmail.com", "00645874920", "2022-11-12", "2022-11-12", NULL),
(NULL, "Jacquinet", "Nathan", "none", "n.j@gmail.com", "76543210", "2022-12-08", "2022-12-08", NULL);

INSERT INTO Interaction VALUES (NULL, "Continuer SR", DATE('now'), 1);
INSERT INTO Interaction VALUES (NULL, "Faire la vaisselle", DATE('now'), 2); 

INSERT INTO Tache VALUES (NULL, "Manger", DATE('now'), 2); 
INSERT INTO Tache VALUES (NULL, "Boire", DATE('now'), 2); 

INSERT INTO Tache VALUES (NULL, "avancer shell script", DATE('now'), 1); 

PRAGMA foreign_keys;
PRAGMA foreign_keys = ON;

SELECT max(IdC) FROM Contact;

-- SELECT count(IdC) FROM Contact
-- PRAGMA foreign_keys = ON;DELETE FROM Contact WHERE IdC = 1;
-- INSERT INTO Contact VALUES (NULL, "Mortier", "Marie", "none", "m.m@gmail.com", "0607080910", "2022-11-12", "2022-11-12", NULL);
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <list>
#include <iostream>

/**
 * @brief Classe Abstraite d'un Gestionnaire de Type T
 */
template<class T>
class Gestionnaire
{
protected:
    ///Déclaration de la list
    ///mutable permet d'autoriser la modification de la liste (et de récupérer les référence des instance dans les listes et de les modifier
    mutable std::list<T> m_list;

public:
    ///Constructeur par défaut
    Gestionnaire();

    ///Renvoie la liste de Type T
    std::list<T> &list() const;

    /**
     * @brief Ajoute une copie de l'instance T dans la liste
     * @param element Instance T à ajouter
     */
    void ajouterElement(const T& element);

    /**
     * @brief Supprimer le premier element correspondant à la tache mit en argument
     * @param element Instance T à supprimer
     */
    bool supprimerElement(const T& element);

    /**
     * @brief Supprime l'élément situé à l'indice de la list
     * @param indice l'Indice de l'élément à supprimer
     * @return True si l'opération a aboutit, false sinon
     */
    bool supprimerElement(const unsigned indice);

    /**
     * @brief Supprime l'instance de T correspondant à l'ID
     * @param Id id de l'instance T
     * @return Si la suppression a aboutit
     */
    virtual bool supprimerParId(const unsigned Id) = 0;

    /**
     * @brief Renvoie le nombre d'élément contenu dans le gestionnaire
     */
    unsigned getNombreElements() const;

    /**
     * @brief Supprime toute les tâche du gestionnaire
     */
    void effacerToutElements();

    /**
     * @brief Permet de récupérer une copie de l'élément à l'indice 'indice' du gestionnaire
     * @param indice
     * @return L'élément correspondant à l'indice 'indice'
     */
    T& getElement(const unsigned indice) const;

    /**
     * @brief Remplace l'instance de l'élément à l'indice précisé, par celle mit en argument
     * @param tache La nouvelle instance
     * @param indice indice de l'instance à remplacer
     * @return true ou false, si le remplacement a abouti
     */
    bool remplacer(const T& tache, const unsigned indice);

    bool operator==(const Gestionnaire<T>& c) const;

    ///Transforme tout le contenu de la liste en flux et l'envoie au flux out
    friend std::ostream& operator<<(std::ostream& out, const Gestionnaire<T>& c)
    {
        for(auto it = c.m_list.begin(); it != c.m_list.end(); ++it)
        {
            out << *it << std::endl;
        }
        return out;
    }

};

                //---- IMPLEMENTATION ----

template<class T>
Gestionnaire<T>::Gestionnaire() {}

template<class T>
void Gestionnaire<T>::ajouterElement(const T& element)
{
    //On fait une copy de l'instance, qui est ensuite ajouté dans la list
    m_list.push_back(element);
}

template<class T>
bool Gestionnaire<T>::supprimerElement(const T& element)
{
    bool finded = false;
    for(auto it = m_list.begin(); it != m_list.end() && !finded; ++it){
        if(*it == element)
        {
            m_list.erase(it);           //On le supprime de la list
            finded = true;              //Pour terminer la boucle
            break;
        }
    }
    return finded;
}

template<class T>
bool Gestionnaire<T>::supprimerElement(const unsigned indice)
{
    if(indice < m_list.size())
    {
        //On récupère l'iterator au début de la liste
        auto element = m_list.begin();
        //On avance dans l'iterator
        std::advance(element, indice);
        //On supprime l'instance désignée
        m_list.erase(element);
        return true;
    }
    return false;
}

template<class T>
unsigned Gestionnaire<T>::getNombreElements() const
{
    return m_list.size();
}

template<class T>
void Gestionnaire<T>::effacerToutElements()
{
    m_list.clear();
}

template<class T>
T& Gestionnaire<T>::getElement(const unsigned indice) const
{
    if(indice < (int) m_list.size())
    {
        auto element = m_list.begin();
        std::advance(element, indice);
        return *element;
    }

    throw std::out_of_range(&"L'indice est out of range " [indice]);

}

template<class T>
bool Gestionnaire<T>::remplacer(const T& toReplace, const unsigned indice)
{
    if(indice < m_list.size())
    {
        //On récupère l'iterator au début de la liste
        auto element = m_list.begin();
        //On avance dans l'iterator à l'indice donné
        std::advance(element, indice);
        //On supprime l'instance désignée de la list
        m_list.erase(element);

        //On retourne au début de la liste
        element = m_list.begin();
        //On se place à l'emplacement où on a enlever l'ancien élément
        std::advance(element, indice);
        //On place une copie de notre instance dans la liste
        m_list.emplace(element, toReplace);
        return true;
    }
    return false;
}

template<class T>
bool Gestionnaire<T>::operator==(const Gestionnaire<T> &c) const
{
    return m_list == c.m_list;
}
#endif // GESTIONNAIRE_H

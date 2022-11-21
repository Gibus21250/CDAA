#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <list>
#include <iostream>

template<class T>
class Gestionnaire
{
protected:
    //Déclaration de la list
    //mutable permet d'autoriser la modification de la liste
    mutable std::list<T> m_list;

public:
    Gestionnaire();

    std::list<T> &list() const;

    void ajouterElement(const T& element);
    /**
     * @brief Supprimer le premier element correspondant à la tache mit en argument
     * @param in
     */
    bool supprimerElement(const T& element);

    /**
     * @brief Supprime l'élément à l'indice de la list
     * @param indice
     * @return True si l'opération a aboutit
     */
    bool supprimerElement(const unsigned indice);

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
    std::pair<T, bool> getElement(const unsigned indice) const;

    /**
     * @brief Remplace l'instance de l'élément à l'indice précisé, par celle mit en argument
     * @param La nouvelle instance
     * @param Indice de l'instance à remplacer
     * @return true ou false, si le remplacement a abouti
     */
    bool remplacer(const T& tache, const unsigned indice);

    bool operator==(const Gestionnaire<T>& c) const;

    friend std::ostream& operator<<(std::ostream& out, const Gestionnaire<T>& c)
    {
        for(auto it = c.m_list.begin(); it != c.m_list.end(); ++it)
        {
            std::cout << *it << std::endl;
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
std::pair<T, bool> Gestionnaire<T>::getElement(const unsigned indice) const
{
    if(indice < (int) m_list.size())
    {
        auto element = m_list.begin();
        std::advance(element, indice);
        return std::make_pair(*element, true);
    }

    return std::make_pair(T(), false);
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

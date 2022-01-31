/*
 * \file   BorneFontaine.cpp
 * \brief implémentation de la classe BorneFontaine
 * \Author Djodji Komlan
 * \Created on 16 mars 2021, 22:39
 */

#include "BorneFontaine.h"
#include "Borne.h"
#include"validationFormat.h"
#include"ContratException.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using namespace util;
namespace bornesQuebec

{

  /**
   * \brief     Le constructeur avec paramrètre de la classe BorneFontaine. Il construit un objet Borne à
   *             partire des données passées en paramètre.
   * \param[in] p_ville,  représente la ville
   * \param[in] p_arrondissement, représente l'arrondissement.
   * \return un objet Borne.
   *
   */
  BorneFontaine::BorneFontaine (int p_identifiant, const string& p_direction,
                                const string& p_nomTopographique, float p_longitude, float p_latitude, const string& p_ville, const string& p_arrondissement) : Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude), m_ville (p_ville), m_arrondissement (p_arrondissement)
  {
    PRECONDITION (!p_ville.empty ());
    PRECONDITION (arrondissementEstValide (p_ville, p_arrondissement));


    POSTCONDITION (p_ville == m_ville);
    POSTCONDITION (m_arrondissement == p_arrondissement);
    INVARIANTS ();
  }

  BorneFontaine::~BorneFontaine () { }

  const std::string&
  BorneFontaine::reqVille ()const
  {

    return m_ville;
  }

  const std::string &
  BorneFontaine::reqArrondissement ()const
  {

    return m_arrondissement;
  }

  /**
   * \brief methode qui permet de faire une copie sur le monceau de l'objet courant
   */

  Borne*
  BorneFontaine::clone ()const
  {
    return new BorneFontaine (*this);
  }

  /**
   * \brief augment la methode de la classe de base
   * \return retourne les information correspondant a une Borne de stationnement.
   */

  std::string
  BorneFontaine::reqBorneFormate () const
  {

    std::ostringstream os;
    os << "Borne-fontaine " << endl;
    os << "----------------------------------------------" << endl;
    os << Borne::reqBorneFormate ();
    os << "Ville: " << m_ville << endl;
    os << "Arrondissement: " << m_arrondissement << endl;
    os << "----------------------------------------------------" << endl;
    return os.str ();
  }

  /**
   * \brief les invariants de la classe BorneFntaine
   */
  void
  BorneFontaine::verifieInvariant ()const
  {
    INVARIANT (!m_ville.empty ());
    INVARIANT (arrondissementEstValide (m_ville, m_arrondissement));
  }
}
//fin namespace bornesQuebec
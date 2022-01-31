

/*
 * \file:   RegistreBorne.cpp
 * \brief définition de la classe RegistreBorne
 * \Author: djodji Komlan
 *
 * \Created on 21 mars 2021, 10:10
 */
#include "RegistreBorne.h"
#include"ContratException.h"
#include<sstream>


/**
 * \brief     Le constructeur avec paramrètre de la classe RegistreBorne. Il construit un objet Borne à
 *             partire des données passées en paramètre.
 * \param[in] p_nomRegistreBorne.
 * \return un objet Borne.
 *
 */
namespace bornesQuebec

{

  RegistreBorne::RegistreBorne (const std::string& p_nomRegistreBorne) :
  m_nomRegistreBorne (p_nomRegistreBorne)
  {

    PRECONDITION (!p_nomRegistreBorne.empty ());

    POSTCONDITION (m_nomRegistreBorne == p_nomRegistreBorne);

    POSTCONDITION (m_vBornes.size () == 0);

    INVARIANTS ();

  }

  RegistreBorne::~RegistreBorne ()
  {
    for (unsigned i = 0; i < m_vBornes.size (); i++)
      {
        delete m_vBornes[i];
      }
  }

  /**
   *Constructeur copie
   *
   */

  RegistreBorne::RegistreBorne (const RegistreBorne& p_registreBorne)
  {
    m_nomRegistreBorne = p_registreBorne.reqNomRegistreBorne ();

    for (unsigned i = 0; i < p_registreBorne.m_vBornes.size (); i++)
      {
        ajouteBorne (*(p_registreBorne.m_vBornes[i]));
      }
  }

  /**
   *Opérateur d'assignation
   */


  const RegistreBorne& RegistreBorne::operator= (const RegistreBorne& p_registreBorne)
  {
    for (unsigned i = 0; i < m_vBornes.size (); i++)

      {
        delete m_vBornes[i];

      }

    m_nomRegistreBorne = p_registreBorne.reqNomRegistreBorne ();

    for (unsigned i = 0; i < p_registreBorne.m_vBornes.size (); i++)
      {
        ajouteBorne (*(p_registreBorne.m_vBornes[i]));
      }
    return *this;
  }

  /**
   * \brief  Accesseur pour le nom du registre de la Borne
   * \return m_nomRegistreBorne le nom du registre de la borne.
   */

  const std::string&
  RegistreBorne::reqNomRegistreBorne ()const
  {
    return m_nomRegistreBorne;
  }

  /**
   * \brief  Methode privée de la classe nom Registre , verifie si la borne
   *        n'est pas déjà dans le vecteur
   * \return true si oui.
   */

  bool
  RegistreBorne::BorneEstDejaPresente (const Borne & p_borne)const
  {
    bool valide = false;
    for (unsigned i = 0; i < m_vBornes.size (); i++)
      {
        if (m_vBornes[i]->reqIdentifiant () == p_borne.reqIdentifiant ())

          {
            valide = true;
          }
      }
    return valide;
  }

  /**
   * \brief  Methode de la classe nom Registre Borne, permet d'ajouter une borne au vecteur de borne
   *        si la borne n'est pas déja présent.
   * \return true si oui.
   */

  void
  RegistreBorne::ajouteBorne (const Borne & p_Borne)
  {
    if (BorneEstDejaPresente (p_Borne) == false)
      {
        m_vBornes.push_back (p_Borne.clone ());
      }

  }

  /**
   * \brief  Methode de la classe nom Registre Borne, permet de formater les informations
   *           concernant le registre Borne
   * \return un objet string.
   */
  std::string
  RegistreBorne::reqRegistreBorneFormate () const
  {
    std::ostringstream os;
    os << "Registre: " << reqNomRegistreBorne () << std::endl;

    for (unsigned i = 0; i < m_vBornes.size (); i++)
      {
        os << m_vBornes[i]->reqBorneFormate ();
      }

    return os.str ();
  }

  /**
   * \brief les invariants de la classe RegistreBorne
   */

  void
  RegistreBorne::verifieInvariant ()const
  {
    INVARIANT (!m_nomRegistreBorne.empty ());
  }

}//fin bornesQuebec




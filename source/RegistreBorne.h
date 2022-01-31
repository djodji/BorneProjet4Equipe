

/**
 * \File:   RegistreBorne.h
 * \brief implémentation des méthodes de la classe registreBorne
 * \Author: Djodji komlan
 * \Created on 21 mars 2021, 12:45
 */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H
#include <vector>

#include"Borne.h"
#include"BorneFontaine.h"
#include"BorneStationnement.h"

namespace bornesQuebec
{

  class RegistreBorne
  /**
   * \class   RegistreBorne
   * \brief   elle permet la gestion des bornes-fontaines et de stationnement
   * \ parametre[in] nom registre borne, un objet string non vide
   */
  {
  public:
    RegistreBorne (const std::string& p_nomRegistreBorne);

    ~RegistreBorne ();
    RegistreBorne (const RegistreBorne& p_registreBorne);
    const RegistreBorne& operator= (const RegistreBorne& p_registreBorne);
    const std::string& reqNomRegistreBorne ()const;
    std::string reqRegistreBorneFormate () const;
    void ajouteBorne (const Borne& p_Borne);



  private:
    std::string m_nomRegistreBorne;
    std::vector<Borne*>m_vBornes;
    bool BorneEstDejaPresente (const Borne&p_borne)const;
    void verifieInvariant ()const;
  };
}//fin bornesQuebec

#endif /* REGISTREBORNE_H */


/**
 * \file    BorneFontaine.h
 * \brief   Déclaration différents prototypes de la classe Borne Fontaine
 * \author  Djodji Komlan
 * \date    16 Mars 2021, 20:07
 */



#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H
#include"Borne.h"
#include"ContratException.h"
#include"validationFormat.h"

namespace bornesQuebec
{

  /**
   * \class   Borne Fontaine, elle dérive de la claase Borne
   * \brief   La classe Borne Fontaine, permettant la modélisation de tous les types de bornes-fontaines
   *          de la ville de Québec.
   * \ parametre[in] ville: un objet string qui représente la ville
   * \ paramtre [in] arrondissement: un objet string, qui désigne l'arrondissement
   *
   */

  class BorneFontaine : public Borne
  {
  public:

    BorneFontaine (int p_identifiant, const std::string& p_direction,
                   const std::string& p_nomTopographique, float p_longitude, float p_latitude, const std::string& p_ville, const std::string& p_arrondissement);

    virtual ~BorneFontaine ();

    const std::string& reqVille ()const;
    const std::string &reqArrondissement ()const;
    virtual Borne* clone () const;

    virtual std::string reqBorneFormate () const;


  private:

    std::string m_ville;
    std::string m_arrondissement;
    void verifieInvariant ()const;
  };
}
//namespace bornesQuebec
#endif /* BORNEFONTAINE_H */


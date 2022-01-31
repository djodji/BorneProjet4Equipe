/**
 * \file    Borne.h
 * \brief   Les différents prototypes de la classe Borne
 * \author  Djodji Komlan
 * \date    18 février 2021, 20:07
 */
#ifndef BORNE_H
#define BORNE_H
#include <string>

#include "validationFormat.h"

namespace bornesQuebec
{

  /**
   * \class   Borne
   * \brief   La classe Borne, permettant la modélisation de tous les types de bornes
   *          présents dans la ville de Québec.
   * \ parametre[in] un identifiants de la borne, un entier strictement positif
   * \ paramtre [in] un objet string, désigne le coté du centre de chaussée ou
   *          l'intersection d'un terre-plein
   * \ parametre[in] le nom topographique du centre de chaussée. non vide
   * \ parametre [in] longitude te latitude, deux nombre réelles
   *     * \
   */
  class Borne
  {
  public:
    Borne (int p_identifiant, const std::string& p_direction,
           const std::string& p_nomTopographique, float p_longitude, float p_latitude);

    virtual
    ~Borne ();

    virtual Borne*clone () const = 0;
    int reqIdentifiant () const;
    const std::string& reqDirection () const;
    const std::string& reqNomTopographique () const;
    float reqLongitude ()const;
    float reqLatitude ()const;
    void asgNomTopographie (const std::string& p_nomTopographique);
    virtual std::string reqBorneFormate () const = 0;
    bool operator== (const Borne& p_Borne) const;


  private:

    int m_identifiant;
    std::string m_direction;
    std::string m_nomTopographique;
    float m_longitude;
    float m_latitude;
    void verifieInvariant ()const;

  };
}//fermeture namespace bornesQuebec

#endif /* BORNE_H */


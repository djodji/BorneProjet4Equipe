/**
 * \file BorneStationnement.h
 * \brief Déclaration de la classe BorneStationnement héritant de la classe Borne
 * \auteur djodji komlan
 * Created on 21 mars 2021, 10:10
 */


#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H
#include"Borne.h"

namespace bornesQuebec
{

  /**
   * \class BorneStationnement
   * \brief classe dérivée de la classe Borne, elle représente les bornes
   *        de stationnement et de payement de la ville de Québec
   * \param[in] un objet string identifie le type borne de stationnement qui peut être stationnement ou                       payement
   * \param[in] lecture Metrique, qui mesure la distance a partir du debut du tronçon.
   *            il est plus grand que 0
   * \param[in] l'identidiant du segement de voie publique (segmentRue)
   * \param[in] le numero de la borne, il est compris entre 1 et 4
   * \param[in] un objet string coteRue valide le cote par rapport au centre de chaussée
   *            où est la borne. la validité est établie par la fonction
   *            util::validationPointCardinal
   *
   */
  class BorneStationnement : public Borne

  {
  public:
    BorneStationnement (int p_identifiant, const std::string& p_direction,
                        const std::string& p_nomTopographique, float p_longitude, float p_latitude, float p_lectureMetrique, int p_segmentRue, int p_numBorne, const std::string& p_coteRue);

    virtual ~BorneStationnement ();

    virtual Borne*clone () const;
    const std::string&reqType ()const;
    float reqLectureMetrique ()const;
    int reqSegmentRue ()const;
    int reqNumBorne ()const;
    const std::string&reqCoteRue ()const;
    virtual std::string reqBorneFormate () const;

  private:

    //std::string m_type;
    float m_lectureMetrique;
    int m_segmentRue;
    int m_numBorne;
    std::string m_coteRue;
    void verifieInvariant ()const;


  };
}//fin bornQuebec

#endif /* BORNESTATIONNEMENT_H */


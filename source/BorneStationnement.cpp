/*
 * \file:   BorneStationnement.cpp
 * \brief définition de la classe BorneStationnement
 * \Author: djodji Komlan
 *
 * \Created on 21 mars 2021, 10:10
 */

#include "BorneStationnement.h"
#include <sstream>
#include<iostream>
#include"ContratException.h"

using namespace std;
namespace bornesQuebec

        /**
         * \brief  Implémentation du constructeur avec paramrètre de la classe BorneStationnement. Il                            construit un objet Borne à partire des données passées en paramètre.
         * \precon type non vide
         * \precon lectureMetrique superieur a 0
         * \precon segmentRue superieur a 0
         * \precon numBorne compris entre 1 et 4
         * \precon coteRue correspont au point cardinal
         * \postcon m_type prend la valeur de p_type
         * \postcon m_lectureMetrique prend la valeur p_lectureMetrique
         * \postcon m_segmentRue prend la valeur p_segmentRue
         * \postcon m_coteRue==p_coteRue
         * \return un objet BorneStationnement.
         *
         */
{

  BorneStationnement::BorneStationnement (int p_identifiant, const string& p_direction,
                                          const string& p_nomTopographique, float p_longitude, float p_latitude, float p_lectureMetrique, int p_segmentRue, int p_numBorne, const std::string&p_coteRue) :
  Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude), m_lectureMetrique (p_lectureMetrique), m_segmentRue (p_segmentRue), m_numBorne (p_numBorne), m_coteRue (p_coteRue)
  {
    //PRECONDITION (!p_type.empty ());
    PRECONDITION (p_lectureMetrique > 0.0);
    PRECONDITION (p_segmentRue > 0);
    PRECONDITION (p_numBorne >= 1 && p_numBorne <= 9999);
    PRECONDITION (!p_coteRue.empty ());

    //POSTCONDITION (m_type == p_type);
    POSTCONDITION (m_lectureMetrique == p_lectureMetrique);
    POSTCONDITION (m_segmentRue == p_segmentRue);
    POSTCONDITION (m_numBorne == p_numBorne);
    POSTCONDITION (m_coteRue == m_coteRue);

  }

  BorneStationnement::~BorneStationnement () { }

  /**
   * \brief methode permettant de faire une copie alloué sur le monceau de l'objet
   * @return
   */

  Borne*
  BorneStationnement::clone ()const
  {
    return new BorneStationnement (*this);
  }

  /**
   * \brief methode d'acces a la lectureMetrique
   * \return l'attribut lectureMetrique
   */
  float
  BorneStationnement::reqLectureMetrique ()const
  {
    return m_lectureMetrique;
  }

  /**
   * \brief methode d'acces au segmentRue
   * \return l'attribut segmentRue
   */
  int
  BorneStationnement::reqSegmentRue ()const
  {
    return m_segmentRue;
  }

  /**
   * \brief methode d'acces au numBorne
   * \return m_numBorne
   */
  int
  BorneStationnement::reqNumBorne ()const
  {
    return m_numBorne;
  }

  /**
   * \brief methode d'acces au coteRue
   * \return m_coteRue
   */
  const std::string&
  BorneStationnement::reqCoteRue ()const
  {
    return m_coteRue;
  }

  /**
   * \brief methode qui augmente la methode de la classe borne
   * \return string
   */
  std::string
  BorneStationnement::reqBorneFormate () const
  {
    std::ostringstream os;
    os << "Borne de stationnement " << endl;
    os << "----------------------------------------------" << endl;
    os << Borne::reqBorneFormate ();
    os << "Distance mesuree : " << m_lectureMetrique << endl;
    os << "Segment de rue : " << m_segmentRue << endl;
    os << "Numero de la borne : " << m_numBorne << endl;
    os << "Cote de la rue : " << m_coteRue << endl;
    os << "----------------------------------------------------" << endl;
    return os.str ();

  }

  /**
   * \brief verifie les invariants de la classe BorneStationnement
   */
  void
  BorneStationnement::verifieInvariant ()const
  {

    INVARIANT (m_lectureMetrique > 0.0);
    INVARIANT (m_segmentRue > 0);
    INVARIANT (m_numBorne >= 1 && m_numBorne <= 9999);
    INVARIANT (!m_coteRue.empty ());
  }

}//fin bornesQuebec


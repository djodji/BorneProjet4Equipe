/**
 * \file     Borne.cpp
 * \brief    L'implémentation de la classe Borne
 * \author   Djodji Komlan
 * \date     18 février 2021, 20:07
 */

#include "Borne.h"
#include <string>
#include <iostream>
#include <sstream>
#include"ContratException.h"
#include "validationFormat.h"

using namespace std;

namespace bornesQuebec
{

  /**
   * \brief     Le constructeur avec paramrètre de la classe. Il construit un objet Borne à
   *             partire des données passées en paramètre.
   * \param[in] p_numBorne le numéro de borne
   * \param[in] p_coteRue le coté par rapport au centre de chaussée où est la borne.
   *             il correcpond à un point cardinal.
   * \param[in] p_lectureMetrique la distance mésurée à partir du début du tronçon
   *             dans le sens des numéros d'immeuble
   * \param[in] p_sepmentRue l'identifiant du segment de voie publique
   * \param[in] p_direction le côté du centre du chaussées ou l'intersection dans le cas d'un
   *             terre-plein. Il correcpond à un point cardinal
   * \param[in] p_nomTopographique le nom topographique (générique, liaison,specifique,direction)
   *             du centre de chaussée
   * \return un objet Borne.
   *
   */

  Borne::Borne (int p_identifiant, const string& p_direction, const string& p_nomTopographique, float p_longitude, float p_latitude) : m_identifiant (p_identifiant), m_direction (p_direction), m_nomTopographique (p_nomTopographique), m_longitude (p_longitude), m_latitude (p_latitude)
  {

    PRECONDITION (p_identifiant > 0);
    PRECONDITION (!p_direction.empty ());
    PRECONDITION (!p_nomTopographique.empty ());



    POSTCONDITION (p_identifiant == m_identifiant);
    POSTCONDITION (p_direction == m_direction);
    POSTCONDITION (p_nomTopographique == m_nomTopographique);
    POSTCONDITION (p_longitude == m_longitude);
    POSTCONDITION (p_latitude == m_latitude);
    INVARIANTS ();
  }

  Borne::~Borne () { }

  /**
   * \brief  Accesseur pour numero de borne
   * \return m_numBorne le numero de borne.
   */
  int
  Borne::reqIdentifiant () const
  {
    return m_identifiant;
  }

  /**
   * \brief Accesseur verifie le centre de chaussée ou l'intersection dans le
   *        cas d'un terre-plein. il est la vidé par la fonction util::validerPointCardinal
   * \return m_direction.
   */
  const string &
  Borne::reqDirection () const
  {
    return m_direction;
  }

  /**
   * \brief Accesseur pour la lecture Métrique
   * \return m_lectureMetrique la distance mesurée
   */
  const string &
  Borne::reqNomTopographique () const
  {
    return m_nomTopographique;
  }

  /**
   * \brief Accesseur pour le segment Rue
   * \return m_segmentRue l'identifiant de la voie
   */

  float
  Borne::reqLongitude () const
  {
    return m_longitude;

  }

  /**
   * \brief Accesseur pour la direction
   * \return m_direction le côté du centre de la chaussée de l'objet
   */

  float
  Borne::reqLatitude () const
  {
    return m_latitude;
  }

  /**
   * \brief  Mutateur pour nom Topographique, modifie m_nomTopographie
   * \param[in] p_nomTopographique.
   */
  void
  Borne::asgNomTopographie (const std::string & p_nomTopographique)
  {
    PRECONDITION (!p_nomTopographique.empty ());

    m_nomTopographique = p_nomTopographique;

    PRECONDITION (m_nomTopographique == p_nomTopographique);
    INVARIANTS ();
  }

  /**
   * \brief Méthode retournant une chaine de caractère qui contient
   *         les informations correspondant à une borne
   * \return un string qui contient l'information.
   */

  std::string
  Borne::reqBorneFormate () const
  {
    ostringstream os;
    os << "Identifiant de la borne: " << m_identifiant << endl
            << "Direction: " << m_direction << endl
            << "Nom Topographique: " << m_nomTopographique << endl
            << "Longitude: " << m_longitude << endl
            << "Latitude: " << m_latitude << endl;

    return os.str ();
  }

  /**
   * \brief Méthode de comparaison d'égalité sur tous les attributs
   * \return un string qui contient l'information.
   */
  bool Borne::operator== (const Borne & p_Borne) const
  {

    return (m_identifiant == p_Borne.reqIdentifiant () && m_direction == p_Borne.reqDirection () && m_nomTopographique == p_Borne.reqNomTopographique () && m_longitude == p_Borne.reqLongitude () && m_latitude == p_Borne.reqLatitude ());


  }

  /**
   * \brief les invariants de la classe Borne
   */

  void
  Borne::verifieInvariant ()const
  {
    INVARIANT (m_identifiant > 0);
    INVARIANT (!m_direction.empty ());
    INVARIANT (!m_nomTopographique.empty ());
    INVARIANT (m_longitude < 0.0 || m_longitude > 0.0);
    INVARIANT (m_latitude < 0.0 || m_latitude > 0.0);

  }
}
//fermeture namespace bornesQuebec
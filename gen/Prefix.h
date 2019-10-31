
#ifndef PREFIX_H_
#define PREFIX_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'prefix'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Prefix_main_region_CERRADO,
	Prefix_main_region_ABIERTO,
	Prefix_main_region_CERRANDO,
	Prefix_main_region_ABRIENDO,
	Prefix_IDLE_ESPERA,
	Prefix_TECX_NO_OPRIMIDO,
	Prefix_TECX_DEBOUNCE,
	Prefix_TECX_VALIDATION,
	Prefix_TECX_OPRIMIDO,
	Prefix_last_state
} PrefixStates;

/*! Type definition of the data structure for the PrefixIface interface scope. */
typedef struct
{
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTurnOn_raised;
	sc_boolean evTurnOff_raised;
	sc_boolean evForma_raised;
	sc_boolean evMagn_raised;
	sc_boolean A_raised;
} PrefixIface;

/* Declaration of constants for scope PrefixIface. */
extern const sc_integer PREFIX_PREFIXIFACE_LED3;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_ON;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_OFF;
extern const sc_integer PREFIX_PREFIXIFACE_TEC1;
extern const sc_integer PREFIX_PREFIXIFACE_TEC2;
extern const sc_integer PREFIX_PREFIXIFACE_TEC3;
extern const sc_integer PREFIX_PREFIXIFACE_TEC4;

/*! Type definition of the data structure for the PrefixInternal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siTitilarLED_raised;
	sc_boolean siNoTitilarLED_raised;
	sc_boolean siAbrir_raised;
	sc_boolean siCerrar_raised;
	sc_boolean siUp_raised;
	sc_boolean siDown_raised;
	sc_integer viTecla;
	sc_integer viFrec;
	sc_integer viTension;
} PrefixInternal;

/*! Type definition of the data structure for the PrefixTimeEvents interface scope. */
typedef struct
{
	sc_boolean prefix_main_region_CERRANDO_tev0_raised;
	sc_boolean prefix_main_region_ABRIENDO_tev0_raised;
	sc_boolean prefix_TECX_DEBOUNCE_tev0_raised;
} PrefixTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PREFIX_MAX_ORTHOGONAL_STATES 3

/*! 
 * Type definition of the data structure for the Prefix state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	PrefixStates stateConfVector[PREFIX_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	PrefixIface iface;
	PrefixInternal internal;
	PrefixTimeEvents timeEvents;
} Prefix;

/*! Initializes the Prefix state machine data structures. Must be called before first usage.*/
extern void prefix_init(Prefix* handle);

/*! Activates the state machine */
extern void prefix_enter(Prefix* handle);

/*! Deactivates the state machine */
extern void prefix_exit(Prefix* handle);

/*! Performs a 'run to completion' step. */
extern void prefix_runCycle(Prefix* handle);

/*! Raises a time event. */
extern void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXNoOprimido(Prefix* handle);

/*! Raises the in event 'evTurnOn' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTurnOn(Prefix* handle);

/*! Raises the in event 'evTurnOff' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTurnOff(Prefix* handle);

/*! Raises the in event 'evForma' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evForma(Prefix* handle);

/*! Raises the in event 'evMagn' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evMagn(Prefix* handle);

/*! Raises the in event 'A' that is defined in the default interface scope. */ 
extern void prefixIface_raise_a(Prefix* handle);

/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED3(const Prefix* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_ON(const Prefix* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC1(const Prefix* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC2(const Prefix* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC3(const Prefix* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC4(const Prefix* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean prefix_isActive(const Prefix* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean prefix_isFinal(const Prefix* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state);

#ifdef __cplusplus
}
#endif 

#endif /* PREFIX_H_ */

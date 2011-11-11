/*
 * fatal.h
 *
 *  Created on: 24-Jul-2010
 *      Author: vivek
 */

#ifndef FATAL_H_
#define FATAL_H_

#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#endif /* FATAL_H_ */

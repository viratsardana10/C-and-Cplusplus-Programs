#include <stdio.h>
#include <stdlib.h>
#include <set>

typedef unsigned int City;
typedef unsigned long long uint64;

#define MODULO 1000000007
#define MAX_CITIES	10001
std::set<City> g_oNeighbours[MAX_CITIES];

char g_sInputBuffer[1024];
char * g_sInputBufferPtr = g_sInputBuffer;
unsigned int g_iInputBufferLength = 0;
uint64 g_iResult = 0;

inline bool IsDigit( char c ) { return ((c >= '0') && (c <= '9')); }

inline char InputReadChar( void )
{
	if( g_iInputBufferLength == 0 )
		{
				g_sInputBufferPtr = g_sInputBuffer;
						g_iInputBufferLength = fread(g_sInputBuffer, 1, sizeof(g_sInputBuffer), stdin);
								if( g_iInputBufferLength == 0 ) return 0;
									}

										g_iInputBufferLength--;
											return *g_sInputBufferPtr++;
											}

											int InputReadTextInt( void )
											{
												char c;
													while( !IsDigit(c = InputReadChar()) );	// Skip blanks

														int iResult = 0;
															do
																{
																		iResult *= 10;
																				iResult += (c - '0');
																						c = InputReadChar();
																							} while( IsDigit(c) );
																								return iResult;
																								}

																								unsigned int DFS(City iCity, City iParentCity)
																								{
																									unsigned int iResult = 1;

																										std::set<City> & oNeighbours = g_oNeighbours[iCity];
																											std::set<City>::const_iterator it = oNeighbours.begin();
																												std::set<City>::const_iterator it_end = oNeighbours.end();
																													while( it != it_end )
																														{
																																City iNextCity = *it;
																																		if( iNextCity != iParentCity )
																																				{
																																							unsigned int iTmpResult = DFS(iNextCity, iCity);
																																										g_iResult += iCity * (uint64)(iResult - 1) * (uint64)iTmpResult * 2;
																																													g_iResult %= MODULO;
																																																iResult += iTmpResult;
																																																		}
																																																				it++;
																																																					}
																																																						g_iResult += (uint64)(iResult - 1) * (uint64)iCity * 2 + iCity;
																																																							g_iResult %= MODULO;
																																																								return iResult;
																																																								}

																																																								void TestCase( void )
																																																								{
																																																									unsigned int iCitiesCount = (City)InputReadTextInt();
																																																										if( iCitiesCount > MAX_CITIES ) iCitiesCount = MAX_CITIES;
																																																											
																																																												if( iCitiesCount == 0 )
																																																													{
																																																															printf("0\n");
																																																																}
																																																																	if( iCitiesCount == 1 )
																																																																		{
																																																																				printf("1\n");
																																																																					}
																																																																						else
																																																																							{
																																																																									for( City iCity = 1; iCity <= iCitiesCount; iCity++ )
																																																																												g_oNeighbours[iCity].clear();

																																																																														// Parse roads to update neighbours
																																																																																for( unsigned int iRoad = 1; iRoad < iCitiesCount; iRoad++ )
																																																																																		{
																																																																																					City iRoadCityA = (City)InputReadTextInt();
																																																																																								City iRoadCityB = (City)InputReadTextInt();
																																																																																											if( iRoadCityA != iRoadCityB )
																																																																																														{
																																																																																																		g_oNeighbours[iRoadCityA].insert(iRoadCityB);
																																																																																																						g_oNeighbours[iRoadCityB].insert(iRoadCityA);
																																																																																																									}
																																																																																																											}

																																																																																																													g_iResult = 0;
																																																																																																															DFS( 1, 1 );
																																																																																																																	printf( "%llu\n", g_iResult );
																																																																																																																		}
																																																																																																																		}

																																																																																																																		int main()
																																																																																																																		{
																																																																																																																		#ifndef ONLINE_JUDGE
																																																																																																																			freopen("input.txt","r",stdin);
																																																																																																																				//freopen("output.txt","w",stdout);
																																																																																																																				#endif

																																																																																																																					unsigned int iTestCasesCount = (City)InputReadTextInt();
																																																																																																																						if( iTestCasesCount > 25 ) iTestCasesCount = 25;
																																																																																																																							
																																																																																																																								while( iTestCasesCount-- )
																																																																																																																									{
																																																																																																																											TestCase();
																																																																																																																												}
																																																																																																																													
																																																																																																																														return 0;
																																																																																																																														}


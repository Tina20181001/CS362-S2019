cmake_minimum_required(VERSION 3.12)
project(dominion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dominion
        cardtest1.c
        cardtest2.c
        cardtest3.c
        cardtest4.c
        dominion.c
        dominion.h
        dominion_helpers.h
        interface.c
        interface.h
        Makefile
        playdom.c
        player.c
        randomtestadventurer.c
        randomtestcard1.c
        randomtestcard2.c
        rngs.c
        rngs.h
        rt.c
        supplyTest.c
        testBuyCard.c
        testDrawCard.c
        testInit.c
        testShuffle.c
        unittest1.c
        unittest2.c
        unittest3.c
        unittest4.c)

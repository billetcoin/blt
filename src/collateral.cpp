// Copyright (c) 2020 The Billetcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight <= 500) {
        nCollateralRequired = 0 * COIN;
    } else if (nHeight <= 2000) {
        nCollateralRequired = 9000 * COIN;
    } else if (nHeight <= 10000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight <= 20000) {
        nCollateralRequired = 20000 * COIN;
    } else if (nHeight <= 30000) {
        nCollateralRequired = 21000 * COIN;
    } else if (nHeight <= 40000) {
        nCollateralRequired = 22000 * COIN;
    } else if (nHeight <= 50000) {
        nCollateralRequired = 25000 * COIN;
    } else if (nHeight <= 70000) {
        nCollateralRequired = 28000 * COIN;
    } else if (nHeight <= 80000) {
        nCollateralRequired = 30000 * COIN;
    } else if (nHeight <= 90000) {
        nCollateralRequired = 35000 * COIN;
    } else if (nHeight <= 100000) {
        nCollateralRequired = 36000 * COIN;
    } else if (nHeight <= 120000) {
        nCollateralRequired = 40000 * COIN;
    } else if (nHeight <= 140000) {
        nCollateralRequired = 45000 * COIN;
    } else if (nHeight <= 150000) {
        nCollateralRequired = 46000 * COIN;
    } else {
        nCollateralRequired = 50000 * COIN;
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}
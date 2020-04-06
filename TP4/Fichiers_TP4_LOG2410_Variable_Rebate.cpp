///////////////////////////////////////////////////////////
//  VariableRebate.cpp
//  Implementation of the Class VariableRebate
//  Created on:      10-mars-2020 16:01:19
//  Original author: francois
///////////////////////////////////////////////////////////

#include "VariableRebate.h"
#include "FixedRebate.h"
#include "OccasionalUserPlan.h"
#include "RegularUserPlan.h"
#include "PremiumUserPlan.h"

namespace PolyCharge
{
	VariableRebate::VariableRebate(AbsSubscriptionPlan& plan, float percent)
		: AbsRebateDecorator(plan), m_basePercent(percent) {

	}

	void VariableRebate::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processVariableRebate(*this);
	}

	Amount VariableRebate::computeCost(kWh charge) const {
		// Apply rebate as visitor to decorated plan to initialize appropriate percentages
		// To use the visitor, its constness must be removed with const_cast
		// To be completed


		// Apply distinct rebates to subscription and energy
		// To be completed

		return  0;
	}

	Amount VariableRebate::computeMarginalCost(kWh purchasedEnergy, kWh extraEnergy) const {
		Amount rebateCost = 0.0;
		if (purchasedEnergy > 0.0f)
		{
			// Apply rebate as visitor to decorated plan to initialize appropriate percentages
			// To use the visitor, its constness must be removed with const_cast
			 // To be completed

			// Apply distinct rebates to subscription and energy
			 // To be completed
		}
		else
		{
			// To be completed
		}

		return  rebateCost;
	}


	void VariableRebate::processFixedRebate(FixedRebate& rebate) {
		// To be completed
	}


	void VariableRebate::processOccasionalPlan(OccasionalUserPlan& plan) {
		// Initialize rebates according to OccasionalPlan
		// To be completed
		m_subscriptionRebate = m_basePercent;
		m_energyRebate = m_basePercent / 5;
	}


	void VariableRebate::processPremiumPlan(PremiumUserPlan& plan) {
		// Initialize rebates according to PremiumPlan
		 // To be completed
		m_subscriptionRebate = m_basePercent;
		m_energyRebate = m_basePercent / 2;
	}


	void VariableRebate::processRegularPlan(RegularUserPlan& plan) {
		// Initialize rebates according to PremiumPlan
		 // To be completed
		m_subscriptionRebate = m_basePercent * 2;
		m_energyRebate = m_basePercent;
	}


	void VariableRebate::processVariableRebate(VariableRebate& rebate) {
		// To be completed
	}

	float PolyCharge::VariableRebate::getRebatePercent() const
	{
		return m_basePercent;
	}

	void PolyCharge::VariableRebate::setRebatePercent(float percent)
	{
		m_basePercent = percent;
	}
}
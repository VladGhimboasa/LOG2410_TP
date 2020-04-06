///////////////////////////////////////////////////////////
//  FixedRebate.cpp
//  Implementation of the Class FixedRebate
//  Created on:      10-mars-2020 16:01:16
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FixedRebate.h"

namespace PolyCharge
{
	FixedRebate::FixedRebate(AbsSubscriptionPlan& plan, float percent)
		: AbsRebateDecorator(plan), m_percent(percent)
	{

	}
	
	void FixedRebate::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processFixedRebate(*this);
	}
	
	Amount FixedRebate::computeCost(kWh charge) const {
		// Compute total energy cost including subscription fees and apply rebate to energy only
		Amount priceSub = m_plan.getSubscriptionCost();
		Amount costEnergyNoRebate = m_plan.computeCost(charge) - priceSub;
		Amount costEnergyRebate = costEnergyNoRebate - (costEnergyNoRebate * m_percent);
		Amount totalCostRebate = priceSub + costEnergyRebate;
		return totalCostRebate;

	}
	
	Amount FixedRebate::computeMarginalCost(kWh purchasedEnergy, kWh extraEnergy) const {
		// Compute marginal energy cost, including subscription fees only if no previous purchase was made, and apply rebate to energy only
		Amount priceSub = m_plan.getSubscriptionCost();
		Amount costEnergyNoRebate = m_plan.computeMarginalCost(purchasedEnergy, extraEnergy) - priceSub;
		Amount costEnergyRebate = costEnergyNoRebate - (costEnergyNoRebate * m_percent);
		Amount totalCostRebate = priceSub + costEnergyRebate;
		return totalCostRebate;
	}

	float FixedRebate::getRebatePercent() const
	{
		return m_percent;
	}
	void FixedRebate::setRebatePercent(float percent)
	{
		this->m_percent = percent;
	}
}
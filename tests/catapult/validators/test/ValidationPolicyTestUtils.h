/**
*** Copyright (c) 2016-present,
*** Jaguar0625, gimre, BloodyRookie, Tech Bureau, Corp. All rights reserved.
***
*** This file is part of Catapult.
***
*** Catapult is free software: you can redistribute it and/or modify
*** it under the terms of the GNU Lesser General Public License as published by
*** the Free Software Foundation, either version 3 of the License, or
*** (at your option) any later version.
***
*** Catapult is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*** GNU Lesser General Public License for more details.
***
*** You should have received a copy of the GNU Lesser General Public License
*** along with Catapult. If not, see <http://www.gnu.org/licenses/>.
**/

#pragma once
#include "catapult/model/Block.h"
#include "catapult/model/WeakEntityInfo.h"

namespace catapult { namespace test {

	/// Wraps a vector of entity infos and their backing memory.
	class EntityInfoContainerWrapper {
	public:
		/// Creates a wrapper around \a count entity infos.
		explicit EntityInfoContainerWrapper(size_t count);

	public:
		/// Gets a vector containing all entity infos.
		model::WeakEntityInfos toVector() const;

	private:
		std::shared_ptr<model::Block> m_pBlock;
		model::BasicContiguousEntityContainer<model::Transaction> m_container;
		std::vector<Hash256> m_hashes;
	};

	/// Creates a wrapper around \a count entity infos such that the entity infos have incrementing timestamps.
	EntityInfoContainerWrapper CreateEntityInfos(size_t count);
}}

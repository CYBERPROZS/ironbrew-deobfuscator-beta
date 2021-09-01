#pragma once

#include "./optimization_passes/base_optimizer.hpp"
#include "./ast/ir/abstract_visitor_pattern.hpp"
#include "./ast/ir/node.hpp"
#include "./ast/ir/statement.hpp"

//#include "ironbrew_devirtualizer/devirtualizer_context/devirtualizer_context.hpp"

namespace deobf::ironbrew_devirtualizer::devirtualizer_markers {
	using namespace ast;

	struct mark_deserializer final : private deobf::optimization_passes::base_optimizer { // marks deserializer, vm string, xor key
		void optimize() override;

		explicit mark_deserializer(ast::ir::statement::block* root) :
			base_optimizer(root)
		{ }
	};
}
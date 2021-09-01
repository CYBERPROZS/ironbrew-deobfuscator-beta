#pragma once

#include "ast/ir/node.hpp"
#include "ast/ir/statement.hpp"
#include "ast/ir/expression.hpp"
#include "ast/ir/abstract_visitor_pattern.hpp"
#include "symbolic_execution/loop_unrolled_bst.hpp"
#include "vm_arch/proto.hpp"

namespace deobf::ironbrew_devirtualizer {
	struct ironbrew_devirtualizer final {
		void devirtualize();
		void proccess_chunk(vm_arch::proto* proto);

		explicit ironbrew_devirtualizer(ast::ir::statement::block* context) :
			context(context)
		{ }
	private:
		ast::ir::statement::block* context; // deobfuscation context
		std::unique_ptr<symbolic_execution::loop_unrolled_bst> search_tree;
	};
}
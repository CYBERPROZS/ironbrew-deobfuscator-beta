#pragma once

#include "../identifier_handler.hpp"

namespace deobf::ironbrew_devirtualizer::opcode_identifiers {
	using namespace ast;

	struct closure_identifier final : public basic_opcode_handler {
		vm_arch::opcode handle(ir::statement::block* path) override {
			auto func_call = path->find_first_of<ir::expression::function_call>();
			if (func_call.has_value()) {
				const auto call_dest = func_call->get().name.value()->to_string();
				if (call_dest == "setmetatable" || call_dest == "wrap") {
					return vm_arch::opcode::op_closure;
				}
			}

			return __super::handle(path);
		}
	};
}
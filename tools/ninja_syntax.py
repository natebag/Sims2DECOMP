"""ninja_syntax.py — minimal NinjaWriter (Apache-2.0, vendored from ninja-build/ninja).

Source: https://github.com/ninja-build/ninja/blob/master/misc/ninja_syntax.py
Trimmed and reformatted for this project. Only the methods we use are kept.
"""

import re
import textwrap


def escape_path(word: str) -> str:
    return word.replace("$ ", "$$ ").replace(" ", "$ ").replace(":", "$:")


def escape(string: str) -> str:
    assert "\n" not in string, "Ninja syntax does not allow newlines in input"
    return string.replace("$", "$$")


def expand(string: str, vars: dict, local_vars: dict | None = None) -> str:
    def exp(m: re.Match[str]) -> str:
        var = m.group(1)
        if var == "$":
            return "$"
        return (local_vars or {}).get(var, vars.get(var, ""))
    return re.sub(r"\$(\$|\w*)", exp, string)


def as_list(input) -> list:
    if input is None:
        return []
    if isinstance(input, list):
        return input
    return [input]


class Writer:
    def __init__(self, output, width: int = 78) -> None:
        self.output = output
        self.width = width

    def newline(self) -> None:
        self.output.write("\n")

    def comment(self, text: str) -> None:
        for line in textwrap.wrap(text, self.width - 2, break_long_words=False, break_on_hyphens=False):
            self.output.write("# " + line + "\n")

    def variable(self, key: str, value, indent: int = 0) -> None:
        if value is None:
            return
        if isinstance(value, list):
            value = " ".join(filter(None, (str(v) for v in value)))
        self._line(f"{key} = {value}", indent)

    def pool(self, name: str, depth: int) -> None:
        self._line(f"pool {name}")
        self.variable("depth", depth, indent=1)

    def rule(
        self,
        name: str,
        command: str,
        description: str | None = None,
        depfile: str | None = None,
        generator: bool = False,
        pool: str | None = None,
        restat: bool = False,
        rspfile: str | None = None,
        rspfile_content: str | None = None,
        deps: str | None = None,
    ) -> None:
        self._line(f"rule {name}")
        self.variable("command", command, indent=1)
        if description:
            self.variable("description", description, indent=1)
        if depfile:
            self.variable("depfile", depfile, indent=1)
        if generator:
            self.variable("generator", "1", indent=1)
        if pool:
            self.variable("pool", pool, indent=1)
        if restat:
            self.variable("restat", "1", indent=1)
        if rspfile:
            self.variable("rspfile", rspfile, indent=1)
        if rspfile_content:
            self.variable("rspfile_content", rspfile_content, indent=1)
        if deps:
            self.variable("deps", deps, indent=1)

    def build(
        self,
        outputs,
        rule: str,
        inputs=None,
        implicit=None,
        order_only=None,
        variables: dict | None = None,
        implicit_outputs=None,
        pool: str | None = None,
        dyndep: str | None = None,
    ) -> list:
        outputs = as_list(outputs)
        out_outputs = [escape_path(x) for x in outputs]
        all_inputs = [escape_path(x) for x in as_list(inputs)]
        if implicit:
            all_inputs.append("|")
            all_inputs.extend(escape_path(x) for x in as_list(implicit))
        if order_only:
            all_inputs.append("||")
            all_inputs.extend(escape_path(x) for x in as_list(order_only))
        if implicit_outputs:
            out_outputs.append("|")
            out_outputs.extend(escape_path(x) for x in as_list(implicit_outputs))
        self._line("build {}: {}".format(" ".join(out_outputs), " ".join([rule] + all_inputs)))
        if pool is not None:
            self._line(f"  pool = {pool}")
        if dyndep is not None:
            self._line(f"  dyndep = {dyndep}")
        if variables:
            for key, val in variables.items():
                self.variable(key, val, indent=1)
        return outputs

    def include(self, path: str) -> None:
        self._line(f"include {path}")

    def subninja(self, path: str) -> None:
        self._line(f"subninja {path}")

    def default(self, paths) -> None:
        self._line("default " + " ".join(as_list(paths)))

    def _line(self, text: str, indent: int = 0) -> None:
        leading = "  " * indent
        # Wrap long lines using $ continuations.
        while len(leading) + len(text) > self.width:
            available = self.width - len(leading) - 2
            space = text.rfind(" ", 0, available)
            if space < 0:
                space = text.find(" ", available)
                if space < 0:
                    break
            self.output.write(leading + text[:space] + " $\n")
            text = text[space + 1:]
            leading = "  " * (indent + 2)
        self.output.write(leading + text + "\n")

    def close(self) -> None:
        self.output.close()

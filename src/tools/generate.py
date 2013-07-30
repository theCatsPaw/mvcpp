import os

import json
basedir = os.getcwd()
basedirgensrc = basedir+"\\src\\app\\gensrc\\"
config = json.load(open(basedir+"\\src\\app\\conf\\conf.json","r"))
print config

from jinja2 import Environment, FileSystemLoader

env = Environment(loader=FileSystemLoader(basedir+"\\src\\gentemplates\\"))


def generate(temp,toFilePath,**kw):
	template = env.get_template(temp)

	template_rendered = template.render(**kw)

	tofile = open(toFilePath,"w")

	tofile.write(template_rendered)

	tofile.close()

generate("conf.cpp.jj",basedirgensrc+"Config.cpp",conf=config)
generate("conf.hpp.jj",basedirgensrc+"Config.hpp",conf=config)
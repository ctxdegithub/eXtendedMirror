##############################################################################
#      Extended Mirror: gen_templ.py                                         #
##############################################################################
#      Copyright (c) 2012-2015, Manuele Finocchiaro                          #
#      All rights reserved.                                                  #
##############################################################################
# Redistribution and use in source and binary forms, with or without         #
# modification, are permitted provided that the following conditions         #
# are met:                                                                   #
#                                                                            #
#    1. Redistributions of source code must retain the above copyright       #
#       notice, this list of conditions and the following disclaimer.        #
#                                                                            #
#    2. Redistributions in binary form must reproduce the above copyright    #
#       notice, this list of conditions and the following disclaimer in      #
#       the documentation and/or other materials provided with the           #
#       distribution.                                                        #
#                                                                            #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"# 
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  #
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE #
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  #
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        #
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF       #
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   #
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    #
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    #
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF     #
# THE POSSIBILITY OF SUCH DAMAGE.                                            #
##############################################################################


import os
import time
import sys

warning_message = "/* WARNING: This file has been autogenerated. \
Do not modify it directly! */"
template_dir = "templ"

variables = {
    'XM_FUNCTION_PARAM_MAX': 8,
    'XM_GET_N_SET_EXTRA_PARAM_MAX': 3,
    'XM_TEMPLATE_PARAM_MAX' : 4,
    'WARNING_MESSAGE' : warning_message
    }

def gen_seq(string, count, sep = ""):
    res = ""
    if type(count) is tuple:
        start = count[0]
        end = count[1]
    else:
        start = 0
        end = count

    for i in range(start, end):
        if i == start:
            res += string.replace("$", str(i))
        else:
            res += sep + string.replace("$", str(i))
    return res 


def generate_files(variables, dirname, names):
    for filename in names:
        fullname = dirname + "/" + filename
        if os.path.isfile(fullname) and filename.endswith(".py"):
            execfile(fullname, variables)
            fullname = fullname[len(template_dir):]
            if fullname.startswith("/"):
                fullname = fullname[1:]
            fullname = fullname[:-len(".py")]
            f = open(fullname, "w")
            f.write(variables["content"])
            f.close()

variables["gen_seq"] = gen_seq


def print_usage():
    print """gen_templ.py -- Generate source files from templates in the the templ folder
             
    Usage: python gen_templ.py [OPTIONS]
                  
    OPTIONS:

        --function-param-max <n_params>: Set the maximum number \
of supported function arguments to n_params.

        --get-n-set-extra-param-max <n_params>: Set the maximum \
number of supported extra parameter for getter and setters, to n_params.

        --template-param-max <n_params>: Set the maximum number \
of supported template parameter to n_params.

        --template-dir <dir>: Set the template directory to dir. """
    exit()


# Process input options
skip_next = False
try:
    for i in range(1, len(sys.argv)):
        if skip_next:
            skip_next = False
            continue
        elif (sys.argv[i] == "--function-param-max"):
            variables["XM_FUNCTION_PARAM_MAX"] = int(sys.argv[i+1])
        elif (sys.argv[i] == "--get-n-set-extra-param-max"):
            variables["XM_GET_N_SET_EXTRA_PARAM_MAX"] = int(sys.argv[i+1])
        elif (sys.argv[i] == "--template-param-max"):
            variables["XM_TEMPLATE_PARAM_MAX"] = int(sys.argv[i+1])
        elif (sys.argv[i] == "--template-dir"):
            template_dir = sys.argv[i+1];
        else:
            print_usage();
        skip_next = True
except:
    print_usage();

if os.path.isdir(template_dir):
    start_time = time.clock()
    os.path.walk(template_dir, generate_files, variables)
    print("completed in: " + str(time.clock() - start_time) + "s")
else:
    print "Error, directory '" + template_dir + "' does not exist"


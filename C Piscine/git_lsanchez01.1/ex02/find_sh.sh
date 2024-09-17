find . -name '*.sh' -print |rev| cut  -d '/' -f1 |rev| cut -d '.' -f1

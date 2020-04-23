(declare-project
  :name "puny-server"
  :description "Small cross platform web server to execute Janet code"
  :author "Matthew Carter"
  :license "GPLv3"
  :url "https://github.com/ahungry/puny-server/"
  :repo "git+https://github.com/ahungry/puny-server.git")

(declare-native
 # Apparently having a dash in name breaks the macros
  :name "punyserver"
  :cflags ["-std=gnu99" "-Wall" "-Wextra" "-fPIC"]
  :lflags ["-lpthread"]
  :source @["puny-server.c" "puny-server-wrap.c"])

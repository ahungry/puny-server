(defn add-headers [res]
  (string/join
   ["HTTP/1.1 200 OK\n"
    "Content-Type: text/html\n"
    "Content-Length: " (string (length res)) "\n"
    "Connection: close\n\n" res] ""))

(defn main [req]
  #(pp req)
  #(pp "in the janet")
  (add-headers "Hello from janet"))

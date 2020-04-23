(import build/punyserver :as ps)

(defn handler [req]
  (pp req)
  "Hello from janet")

(ps/start (fn [req] (pp req) "Hmmm..."))

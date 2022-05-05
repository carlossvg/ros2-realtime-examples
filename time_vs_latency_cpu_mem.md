<script type="text/javascript"
        src="https://cdn.bokeh.org/bokeh/release/bokeh-2.4.2.min.js"></script>

# Latency, CPU and Memory Usage over Time

This is an example performance report generated to markdown.

#### Compare latency for different transports


<script type="text/javascript">
    (function() {
          const fn = function() {
            Bokeh.safely(function() {
              (function(root) {
                function embed_document(root) {
                  
                const docs_json = '{"6ac939b2-1328-45e4-891c-d9f29d83fed0":{"defs":[],"roots":{"references":[{"attributes":{},"id":"1026","type":"HelpTool"},{"attributes":{"axis":{"id":"1017"},"coordinates":null,"dimension":1,"group":null,"ticker":null},"id":"1020","type":"Grid"},{"attributes":{},"id":"1011","type":"LinearScale"},{"attributes":{},"id":"1009","type":"LinearScale"},{"attributes":{},"id":"1040","type":"BasicTickFormatter"},{"attributes":{},"id":"1005","type":"DataRange1d"},{"attributes":{},"id":"1041","type":"AllLabels"},{"attributes":{"axis":{"id":"1013"},"coordinates":null,"group":null,"ticker":null},"id":"1016","type":"Grid"},{"attributes":{"axis_label":"Latency (ms)","coordinates":null,"formatter":{"id":"1037"},"group":null,"major_label_policy":{"id":"1038"},"ticker":{"id":"1018"}},"id":"1017","type":"LinearAxis"},{"attributes":{},"id":"1037","type":"BasicTickFormatter"},{"attributes":{"overlay":{"id":"1027"}},"id":"1023","type":"BoxZoomTool"},{"attributes":{"tools":[{"id":"1021"},{"id":"1022"},{"id":"1023"},{"id":"1024"},{"id":"1025"},{"id":"1026"}]},"id":"1028","type":"Toolbar"},{"attributes":{"below":[{"id":"1013"}],"center":[{"id":"1016"},{"id":"1020"}],"left":[{"id":"1017"}],"margin":[10,10,10,10],"title":{"id":"1003"},"toolbar":{"id":"1028"},"width":1000,"x_range":{"id":"1005"},"x_scale":{"id":"1009"},"y_range":{"id":"1007"},"y_scale":{"id":"1011"}},"id":"1002","subtype":"Figure","type":"Plot"},{"attributes":{},"id":"1021","type":"PanTool"},{"attributes":{},"id":"1025","type":"ResetTool"},{"attributes":{},"id":"1024","type":"SaveTool"},{"attributes":{},"id":"1038","type":"AllLabels"},{"attributes":{"coordinates":null,"group":null,"text":"Comparing different Apex.OS Transports"},"id":"1003","type":"Title"},{"attributes":{},"id":"1018","type":"BasicTicker"},{"attributes":{"bottom_units":"screen","coordinates":null,"fill_alpha":0.5,"fill_color":"lightgrey","group":null,"left_units":"screen","level":"overlay","line_alpha":1.0,"line_color":"black","line_dash":[4,4],"line_width":2,"right_units":"screen","syncable":false,"top_units":"screen"},"id":"1027","type":"BoxAnnotation"},{"attributes":{},"id":"1022","type":"WheelZoomTool"},{"attributes":{},"id":"1014","type":"BasicTicker"},{"attributes":{"axis_label":"Time (seconds)","coordinates":null,"formatter":{"id":"1040"},"group":null,"major_label_policy":{"id":"1041"},"ticker":{"id":"1014"}},"id":"1013","type":"LinearAxis"},{"attributes":{},"id":"1007","type":"DataRange1d"}],"root_ids":["1002"]},"title":"Bokeh Application","version":"2.4.2"}}';
                const render_items = [{"docid":"6ac939b2-1328-45e4-891c-d9f29d83fed0","root_ids":["1002"],"roots":{"1002":"434e5c69-7e11-4736-aa1a-4ff21c3da84d"}}];
                root.Bokeh.embed.embed_items(docs_json, render_items);
              
                }
                if (root.Bokeh !== undefined) {
                  embed_document(root);
                } else {
                  let attempts = 0;
                  const timer = setInterval(function(root) {
                    if (root.Bokeh !== undefined) {
                      clearInterval(timer);
                      embed_document(root);
                    } else {
                      attempts++;
                      if (attempts > 100) {
                        clearInterval(timer);
                        console.log("Bokeh: ERROR: Unable to run BokehJS code because BokehJS library is missing");
                      }
                    }
                  }, 10, root)
                }
              })(window);
            });
          };
          if (document.readyState != "loading") fn();
          else document.addEventListener("DOMContentLoaded", fn);
        })();
</script>
<div class="bk-root" id="434e5c69-7e11-4736-aa1a-4ff21c3da84d" data-root-id="1002"></div>

#### Compare CPU usage for different transports


<script type="text/javascript">
    (function() {
          const fn = function() {
            Bokeh.safely(function() {
              (function(root) {
                function embed_document(root) {
                  
                const docs_json = '{"63e9e782-f90c-4275-be01-d4bb5e1240f9":{"defs":[],"roots":{"references":[{"attributes":{},"id":"1087","type":"WheelZoomTool"},{"attributes":{"overlay":{"id":"1092"}},"id":"1088","type":"BoxZoomTool"},{"attributes":{"axis_label":"CPU Usage (%)","coordinates":null,"formatter":{"id":"1102"},"group":null,"major_label_policy":{"id":"1103"},"ticker":{"id":"1083"}},"id":"1082","type":"LinearAxis"},{"attributes":{},"id":"1102","type":"BasicTickFormatter"},{"attributes":{"coordinates":null,"group":null,"text":"Comparing different Apex.OS Transports CPU Usage (%)"},"id":"1068","type":"Title"},{"attributes":{},"id":"1072","type":"DataRange1d"},{"attributes":{},"id":"1090","type":"ResetTool"},{"attributes":{},"id":"1103","type":"AllLabels"},{"attributes":{},"id":"1106","type":"AllLabels"},{"attributes":{},"id":"1089","type":"SaveTool"},{"attributes":{"axis":{"id":"1082"},"coordinates":null,"dimension":1,"group":null,"ticker":null},"id":"1085","type":"Grid"},{"attributes":{"below":[{"id":"1078"}],"center":[{"id":"1081"},{"id":"1085"}],"left":[{"id":"1082"}],"margin":[10,10,10,10],"title":{"id":"1068"},"toolbar":{"id":"1093"},"width":1000,"x_range":{"id":"1070"},"x_scale":{"id":"1074"},"y_range":{"id":"1072"},"y_scale":{"id":"1076"}},"id":"1067","subtype":"Figure","type":"Plot"},{"attributes":{},"id":"1074","type":"LinearScale"},{"attributes":{},"id":"1079","type":"BasicTicker"},{"attributes":{},"id":"1105","type":"BasicTickFormatter"},{"attributes":{},"id":"1086","type":"PanTool"},{"attributes":{},"id":"1091","type":"HelpTool"},{"attributes":{},"id":"1076","type":"LinearScale"},{"attributes":{},"id":"1070","type":"DataRange1d"},{"attributes":{"axis":{"id":"1078"},"coordinates":null,"group":null,"ticker":null},"id":"1081","type":"Grid"},{"attributes":{"tools":[{"id":"1086"},{"id":"1087"},{"id":"1088"},{"id":"1089"},{"id":"1090"},{"id":"1091"}]},"id":"1093","type":"Toolbar"},{"attributes":{"bottom_units":"screen","coordinates":null,"fill_alpha":0.5,"fill_color":"lightgrey","group":null,"left_units":"screen","level":"overlay","line_alpha":1.0,"line_color":"black","line_dash":[4,4],"line_width":2,"right_units":"screen","syncable":false,"top_units":"screen"},"id":"1092","type":"BoxAnnotation"},{"attributes":{"axis_label":"Time (seconds)","coordinates":null,"formatter":{"id":"1105"},"group":null,"major_label_policy":{"id":"1106"},"ticker":{"id":"1079"}},"id":"1078","type":"LinearAxis"},{"attributes":{},"id":"1083","type":"BasicTicker"}],"root_ids":["1067"]},"title":"Bokeh Application","version":"2.4.2"}}';
                const render_items = [{"docid":"63e9e782-f90c-4275-be01-d4bb5e1240f9","root_ids":["1067"],"roots":{"1067":"3ff5a0b5-f6bb-4afb-838c-972f76c61863"}}];
                root.Bokeh.embed.embed_items(docs_json, render_items);
              
                }
                if (root.Bokeh !== undefined) {
                  embed_document(root);
                } else {
                  let attempts = 0;
                  const timer = setInterval(function(root) {
                    if (root.Bokeh !== undefined) {
                      clearInterval(timer);
                      embed_document(root);
                    } else {
                      attempts++;
                      if (attempts > 100) {
                        clearInterval(timer);
                        console.log("Bokeh: ERROR: Unable to run BokehJS code because BokehJS library is missing");
                      }
                    }
                  }, 10, root)
                }
              })(window);
            });
          };
          if (document.readyState != "loading") fn();
          else document.addEventListener("DOMContentLoaded", fn);
        })();
</script>
<div class="bk-root" id="3ff5a0b5-f6bb-4afb-838c-972f76c61863" data-root-id="1067"></div>

#### Compare latency vs msg size for different transports


<script type="text/javascript">
    (function() {
          const fn = function() {
            Bokeh.safely(function() {
              (function(root) {
                function embed_document(root) {
                  
                const docs_json = '{"d3765867-67e8-46fc-b3ad-c00808ad773f":{"defs":[],"roots":{"references":[{"attributes":{},"id":"1151","type":"WheelZoomTool"},{"attributes":{"axis_label":"Message Size","coordinates":null,"formatter":{"id":"1182"},"group":null,"major_label_policy":{"id":"1183"},"ticker":{"id":"1144"}},"id":"1143","type":"CategoricalAxis"},{"attributes":{},"id":"1155","type":"HelpTool"},{"attributes":{},"id":"1141","type":"LinearScale"},{"attributes":{"callback":null,"tooltips":[["Latency (ms)","@{latency_mean_ms}{0.0000}"]]},"id":"1189","type":"HoverTool"},{"attributes":{},"id":"1154","type":"ResetTool"},{"attributes":{},"id":"1144","type":"CategoricalTicker"},{"attributes":{},"id":"1184","type":"UnionRenderers"},{"attributes":{},"id":"1183","type":"AllLabels"},{"attributes":{"axis":{"id":"1146"},"coordinates":null,"dimension":1,"group":null,"ticker":null},"id":"1149","type":"Grid"},{"attributes":{},"id":"1139","type":"CategoricalScale"},{"attributes":{"line_alpha":0.2,"line_color":"#0000ff","line_width":2,"x":{"field":"msg"},"y":{"field":"latency_mean_ms"}},"id":"1174","type":"Line"},{"attributes":{},"id":"1180","type":"AllLabels"},{"attributes":{"coordinates":null,"group":null,"text":"Comparing Latency over Message Size"},"id":"1134","type":"Title"},{"attributes":{"label":{"value":"INTRA 1 subs"},"renderers":[{"id":"1175"}]},"id":"1188","type":"LegendItem"},{"attributes":{},"id":"1182","type":"CategoricalTickFormatter"},{"attributes":{"coordinates":null,"group":null,"items":[{"id":"1188"}]},"id":"1187","type":"Legend"},{"attributes":{},"id":"1137","type":"DataRange1d"},{"attributes":{},"id":"1153","type":"SaveTool"},{"attributes":{},"id":"1179","type":"BasicTickFormatter"},{"attributes":{"axis":{"id":"1143"},"coordinates":null,"group":null,"ticker":null},"id":"1145","type":"Grid"},{"attributes":{"overlay":{"id":"1156"}},"id":"1152","type":"BoxZoomTool"},{"attributes":{"source":{"id":"1164"}},"id":"1176","type":"CDSView"},{"attributes":{},"id":"1150","type":"PanTool"},{"attributes":{"bottom_units":"screen","coordinates":null,"fill_alpha":0.5,"fill_color":"lightgrey","group":null,"left_units":"screen","level":"overlay","line_alpha":1.0,"line_color":"black","line_dash":[4,4],"line_width":2,"right_units":"screen","syncable":false,"top_units":"screen"},"id":"1156","type":"BoxAnnotation"},{"attributes":{"data":{"T_experiment":{"__ndarray__":"LVcUg22BT0A=","dtype":"float64","order":"little","shape":[1]},"com_mean":["rclcpp-single-threaded-executor"],"cpu_info_cpu_cores":{"__ndarray__":"AAAAAAAAIEA=","dtype":"float64","order":"little","shape":[1]},"cpu_info_cpu_usage":{"__ndarray__":"/rqkGi/p1T8=","dtype":"float64","order":"little","shape":[1]},"cpu_usage_percent":{"__ndarray__":"FrLQzCweQUA=","dtype":"float64","order":"little","shape":[1]},"durability":["VOLATILE"],"experiment_start":{"__ndarray__":"B8/b1INXLUI=","dtype":"float64","order":"little","shape":[1]},"history":["KEEP_LAST"],"history_depth":[16],"ignore_seconds":[5],"index":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"latency_M2":{"__ndarray__":"MIXtbSaOxT4=","dtype":"float64","order":"little","shape":[1]},"latency_M2_ms":{"__ndarray__":"WdgtnoSOBEA=","dtype":"float64","order":"little","shape":[1]},"latency_max":{"__ndarray__":"6drk+dznQj8=","dtype":"float64","order":"little","shape":[1]},"latency_max_ms":{"__ndarray__":"x30JzG124j8=","dtype":"float64","order":"little","shape":[1]},"latency_mean":{"__ndarray__":"IdLcTQkbJj8=","dtype":"float64","order":"little","shape":[1]},"latency_mean_ms":{"__ndarray__":"NKUJFmeWxT8=","dtype":"float64","order":"little","shape":[1]},"latency_min":{"__ndarray__":"gebtoXSaBD8=","dtype":"float64","order":"little","shape":[1]},"latency_min_ms":{"__ndarray__":"G1Mi5tUepD8=","dtype":"float64","order":"little","shape":[1]},"latency_n":{"__ndarray__":"KNpq8BwBWUA=","dtype":"float64","order":"little","shape":[1]},"latency_variance":{"__ndarray__":"Er3vDAeXWz4=","dtype":"float64","order":"little","shape":[1]},"latency_variance_ms":{"__ndarray__":"7FFS9dNPmj8=","dtype":"float64","order":"little","shape":[1]},"level_0":[0],"loop_start":{"__ndarray__":"yEKWJmTOzUE=","dtype":"float64","order":"little","shape":[1]},"max_runtime":[30],"msg":["Array1k"],"num_samples_lost":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"num_samples_received":{"__ndarray__":"KNpq8BzBWEA=","dtype":"float64","order":"little","shape":[1]},"num_samples_sent":{"__ndarray__":"KNpq8BzBWEA=","dtype":"float64","order":"little","shape":[1]},"pub_loop_time_reserve_M2":{"__ndarray__":"RgdXcuy+qT4=","dtype":"float64","order":"little","shape":[1]},"pub_loop_time_reserve_max":{"__ndarray__":"xM7Cj1tRhD8=","dtype":"float64","order":"little","shape":[1]},"pub_loop_time_reserve_mean":{"__ndarray__":"ToK+9ncRhD8=","dtype":"float64","order":"little","shape":[1]},"pub_loop_time_reserve_min":{"__ndarray__":"fWDkYgF2gz8=","dtype":"float64","order":"little","shape":[1]},"pub_loop_time_reserve_n":{"__ndarray__":"KNpq8BwBWUA=","dtype":"float64","order":"little","shape":[1]},"pub_loop_time_reserve_variance":{"__ndarray__":"/1TJLbp5QD4=","dtype":"float64","order":"little","shape":[1]},"pubs":[1],"rate":[100],"reliability":["RELIABLE"],"rt_cpus":[0],"rt_prio":[0],"ru_maxrss":{"__ndarray__":"AAAAAABizUA=","dtype":"float64","order":"little","shape":[1]},"sub_loop_time_reserve_M2":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sub_loop_time_reserve_max":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sub_loop_time_reserve_mean":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sub_loop_time_reserve_min":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sub_loop_time_reserve_n":{"__ndarray__":"niNQtNUAaUA=","dtype":"float64","order":"little","shape":[1]},"sub_loop_time_reserve_variance":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"subs":[1],"sys_tracker_ru_idrss":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_inblock":{"__ndarray__":"AAAAAADq10A=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_isrss":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_ixrss":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_majflt":{"__ndarray__":"AAAAAABgZEA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_maxrss":{"__ndarray__":"AAAAAABizUA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_minflt":{"__ndarray__":"o60GzxGgjEA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_msgrcv":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_msgsnd":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_nivcsw":{"__ndarray__":"qXwY9+sSSEA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_nsignals":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_nswap":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_nvcsw":{"__ndarray__":"JpUP4340yUA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_oublock":{"__ndarray__":"AAAAAAAAAAA=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_stime":{"__ndarray__":"velNhzk1sEE=","dtype":"float64","order":"little","shape":[1]},"sys_tracker_ru_utime":{"__ndarray__":"FrKQu0G+1kE=","dtype":"float64","order":"little","shape":[1]},"total_data_received":{"__ndarray__":"Uvkw7gdk+UA=","dtype":"float64","order":"little","shape":[1]},"transport":["INTRA"]},"selected":{"id":"1185"},"selection_policy":{"id":"1184"}},"id":"1164","type":"ColumnDataSource"},{"attributes":{"source":{"id":"1164"}},"id":"1170","type":"CDSView"},{"attributes":{},"id":"1147","type":"BasicTicker"},{"attributes":{"factors":["Array1k"]},"id":"1132","type":"FactorRange"},{"attributes":{"line_alpha":0.1,"line_color":"#0000ff","line_width":2,"x":{"field":"msg"},"y":{"field":"latency_mean_ms"}},"id":"1173","type":"Line"},{"attributes":{"tools":[{"id":"1150"},{"id":"1151"},{"id":"1152"},{"id":"1153"},{"id":"1154"},{"id":"1155"},{"id":"1189"}]},"id":"1157","type":"Toolbar"},{"attributes":{"axis_label":"Latency (ms)","coordinates":null,"formatter":{"id":"1179"},"group":null,"major_label_policy":{"id":"1180"},"ticker":{"id":"1147"}},"id":"1146","type":"LinearAxis"},{"attributes":{"line_color":"#0000ff","line_width":2,"x":{"field":"msg"},"y":{"field":"latency_mean_ms"}},"id":"1172","type":"Line"},{"attributes":{"fill_alpha":{"value":0.1},"fill_color":{"value":"#0000ff"},"hatch_alpha":{"value":0.1},"line_alpha":{"value":0.1},"line_color":{"value":"#1f77b4"},"marker":{"value":"dot"},"size":{"value":25},"x":{"field":"msg"},"y":{"field":"latency_mean_ms"}},"id":"1167","type":"Scatter"},{"attributes":{"coordinates":null,"data_source":{"id":"1164"},"glyph":{"id":"1166"},"group":null,"hover_glyph":null,"muted_glyph":{"id":"1168"},"name":"INTRA 1 subs dot","nonselection_glyph":{"id":"1167"},"view":{"id":"1170"}},"id":"1169","type":"GlyphRenderer"},{"attributes":{"fill_alpha":{"value":0.2},"fill_color":{"value":"#0000ff"},"hatch_alpha":{"value":0.2},"line_alpha":{"value":0.2},"line_color":{"value":"#1f77b4"},"marker":{"value":"dot"},"size":{"value":25},"x":{"field":"msg"},"y":{"field":"latency_mean_ms"}},"id":"1168","type":"Scatter"},{"attributes":{},"id":"1185","type":"Selection"},{"attributes":{"below":[{"id":"1143"}],"center":[{"id":"1145"},{"id":"1149"},{"id":"1187"}],"left":[{"id":"1146"}],"margin":[10,10,10,10],"name":"compare_msg_size","renderers":[{"id":"1169"},{"id":"1175"}],"title":{"id":"1134"},"toolbar":{"id":"1157"},"width":1000,"x_range":{"id":"1132"},"x_scale":{"id":"1139"},"y_range":{"id":"1137"},"y_scale":{"id":"1141"}},"id":"1133","subtype":"Figure","type":"Plot"},{"attributes":{"coordinates":null,"data_source":{"id":"1164"},"glyph":{"id":"1172"},"group":null,"hover_glyph":null,"muted_glyph":{"id":"1174"},"name":"INTRA 1 subs","nonselection_glyph":{"id":"1173"},"view":{"id":"1176"}},"id":"1175","type":"GlyphRenderer"},{"attributes":{"fill_color":{"value":"#0000ff"},"line_color":{"value":"#1f77b4"},"marker":{"value":"dot"},"size":{"value":25},"x":{"field":"msg"},"y":{"field":"latency_mean_ms"}},"id":"1166","type":"Scatter"}],"root_ids":["1133"]},"title":"Bokeh Application","version":"2.4.2"}}';
                const render_items = [{"docid":"d3765867-67e8-46fc-b3ad-c00808ad773f","root_ids":["1133"],"roots":{"1133":"46feead3-d1eb-45a4-95ef-831a94783991"}}];
                root.Bokeh.embed.embed_items(docs_json, render_items);
              
                }
                if (root.Bokeh !== undefined) {
                  embed_document(root);
                } else {
                  let attempts = 0;
                  const timer = setInterval(function(root) {
                    if (root.Bokeh !== undefined) {
                      clearInterval(timer);
                      embed_document(root);
                    } else {
                      attempts++;
                      if (attempts > 100) {
                        clearInterval(timer);
                        console.log("Bokeh: ERROR: Unable to run BokehJS code because BokehJS library is missing");
                      }
                    }
                  }, 10, root)
                }
              })(window);
            });
          };
          if (document.readyState != "loading") fn();
          else document.addEventListener("DOMContentLoaded", fn);
        })();
</script>
<div class="bk-root" id="46feead3-d1eb-45a4-95ef-831a94783991" data-root-id="1133"></div>

#### Compare latency vs msg size for different number of subscribers


<script type="text/javascript">
    (function() {
          const fn = function() {
            Bokeh.safely(function() {
              (function(root) {
                function embed_document(root) {
                  
                const docs_json = '{"ce082d93-2a0e-4b3d-9feb-77c3163e742f":{"defs":[],"roots":{"references":[{"attributes":{},"id":"1249","type":"PanTool"},{"attributes":{},"id":"1240","type":"LinearScale"},{"attributes":{"overlay":{"id":"1255"}},"id":"1251","type":"BoxZoomTool"},{"attributes":{},"id":"1231","type":"FactorRange"},{"attributes":{},"id":"1254","type":"HelpTool"},{"attributes":{},"id":"1243","type":"CategoricalTicker"},{"attributes":{"bottom_units":"screen","coordinates":null,"fill_alpha":0.5,"fill_color":"lightgrey","group":null,"left_units":"screen","level":"overlay","line_alpha":1.0,"line_color":"black","line_dash":[4,4],"line_width":2,"right_units":"screen","syncable":false,"top_units":"screen"},"id":"1255","type":"BoxAnnotation"},{"attributes":{},"id":"1238","type":"CategoricalScale"},{"attributes":{},"id":"1246","type":"BasicTicker"},{"attributes":{"below":[{"id":"1242"}],"center":[{"id":"1244"},{"id":"1248"}],"left":[{"id":"1245"}],"margin":[10,10,10,10],"name":"compare_num_subs","title":{"id":"1233"},"toolbar":{"id":"1256"},"width":1000,"x_range":{"id":"1231"},"x_scale":{"id":"1238"},"y_range":{"id":"1236"},"y_scale":{"id":"1240"}},"id":"1232","subtype":"Figure","type":"Plot"},{"attributes":{},"id":"1253","type":"ResetTool"},{"attributes":{},"id":"1268","type":"CategoricalTickFormatter"},{"attributes":{},"id":"1236","type":"DataRange1d"},{"attributes":{},"id":"1266","type":"AllLabels"},{"attributes":{"tools":[{"id":"1249"},{"id":"1250"},{"id":"1251"},{"id":"1252"},{"id":"1253"},{"id":"1254"}]},"id":"1256","type":"Toolbar"},{"attributes":{"axis_label":"Number of Subscribers","coordinates":null,"formatter":{"id":"1268"},"group":null,"major_label_policy":{"id":"1269"},"ticker":{"id":"1243"}},"id":"1242","type":"CategoricalAxis"},{"attributes":{},"id":"1269","type":"AllLabels"},{"attributes":{"axis":{"id":"1242"},"coordinates":null,"group":null,"ticker":null},"id":"1244","type":"Grid"},{"attributes":{"coordinates":null,"group":null,"text":"Comparing Latency over Number of Subscribers with Zero Copy"},"id":"1233","type":"Title"},{"attributes":{"axis_label":"Latency (ms)","coordinates":null,"formatter":{"id":"1265"},"group":null,"major_label_policy":{"id":"1266"},"ticker":{"id":"1246"}},"id":"1245","type":"LinearAxis"},{"attributes":{"axis":{"id":"1245"},"coordinates":null,"dimension":1,"group":null,"ticker":null},"id":"1248","type":"Grid"},{"attributes":{},"id":"1250","type":"WheelZoomTool"},{"attributes":{},"id":"1265","type":"BasicTickFormatter"},{"attributes":{},"id":"1252","type":"SaveTool"}],"root_ids":["1232"]},"title":"Bokeh Application","version":"2.4.2"}}';
                const render_items = [{"docid":"ce082d93-2a0e-4b3d-9feb-77c3163e742f","root_ids":["1232"],"roots":{"1232":"15622c77-6372-4af7-a701-de5d07e2e5bc"}}];
                root.Bokeh.embed.embed_items(docs_json, render_items);
              
                }
                if (root.Bokeh !== undefined) {
                  embed_document(root);
                } else {
                  let attempts = 0;
                  const timer = setInterval(function(root) {
                    if (root.Bokeh !== undefined) {
                      clearInterval(timer);
                      embed_document(root);
                    } else {
                      attempts++;
                      if (attempts > 100) {
                        clearInterval(timer);
                        console.log("Bokeh: ERROR: Unable to run BokehJS code because BokehJS library is missing");
                      }
                    }
                  }, 10, root)
                }
              })(window);
            });
          };
          if (document.readyState != "loading") fn();
          else document.addEventListener("DOMContentLoaded", fn);
        })();
</script>
<div class="bk-root" id="15622c77-6372-4af7-a701-de5d07e2e5bc" data-root-id="1232"></div>
// Mapping tanh values from -2 to 1.99609375 with a step of 0.00390625

quantized_type tanh_vals[1024] = { -0.9640275800758169, -0.9637505585110627, -0.963471443296286, -0.9631902192215166, -0.9629068709757654, -0.9626213831465018, -0.9623337402191307, -0.9620439265764688, -0.9617519264982222, -0.9614577241604624, -0.9611613036351028, -0.9608626488893753, -0.9605617437853068, -0.9602585720791958, -0.9599531174210895, -0.95964536335426, -0.9593352933146825, -0.9590228906305123, -0.9587081385215631, -0.9583910200987853, -0.958071518363745, -0.9577496162081036, -0.9574252964130979, -0.9570985416490212, -0.9567693344747047, -0.9564376573370004, -0.9561034925702643, -0.955766822395841, -0.955427628921549, -0.9550858941411678, -0.9547415999339255, -0.9543947280639877, -0.9540452601799487, -0.9536931778143231, -0.953338462383039, -0.952981095184934, -0.9526210574012511, -0.9522583300951382, -0.9518928942111476, -0.9515247305747395, -0.9511538198917856, -0.9507801427480761, -0.9504036796088287, -0.9500244108181993, -0.9496423165987963, -0.9492573770511957, -0.9488695721534608, -0.948478881760663, -0.9480852856044063, -0.9476887632923543, -0.9472892943077605, -0.9468868580090015, -0.9464814336291137, -0.9460730002753329, -0.9456615369286379, -0.9452470224432973, -0.94482943554642, -0.9444087548375099, -0.9439849587880237, -0.943558025740934, -0.9431279339102947, -0.9426946613808131, -0.9422581861074242, -0.9418184859148706, -0.9413755384972874, -0.9409293214177904, -0.9404798121080715, -0.940026987867997, -0.939570825865212, -0.9391113031347509, -0.9386483965786518, -0.9381820829655777, -0.937712338930443, -0.9372391409740465, -0.936762465462709, -0.9362822886279191, -0.9357985865659837, -0.9353113352376858, -0.9348205104679493, -0.9343260879455095, -0.9338280432225917, -0.9333263517145964, -0.932820988699792, -0.9323119293190149, -0.9317991485753769, -0.931282621333982, -0.9307623223216483, -0.9302382261266414, -0.9297103071984134, -0.9291785398473523, -0.9286428982445389, -0.9281033564215134, -0.9275598882700505, -0.9270124675419444, -0.9264610678488026, -0.9259056626618496, -0.925346225311741, -0.9247827289883869, -0.9242151467407852, -0.9236434514768671, -0.9230676159633514, -0.9224876128256104, -0.9219034145475472, -0.9213149934714836, -0.92072232179806, -0.9201253715861468, -0.919524114752768, -0.9189185230730362, -0.9183085681801013, -0.9176942215651103, -0.9170754545771808, -0.9164522384233875, -0.9158245441687624, -0.9151923427363066, -0.9145556049070189, -0.9139143013199357, -0.9132684024721864, -0.9126178787190637, -0.9119627002741072, -0.9113028372092032, -0.9106382594546996, -0.9099689367995354, -0.9092948388913872, -0.9086159352368307, -0.9079321952015192, -0.9072435880103779, -0.9065500827478152, -0.9058516483579518, -0.9051482536448664, -0.9044398672728585, -0.9037264577667303, -0.9030079935120863, -0.9022844427556502, -0.9015557736056028, -0.9008219540319365, -0.9000829518668307, -0.8993387348050462, -0.898589270404339, -0.897834526085895, -0.8970744691347852, -0.8963090667004403, -0.8955382857971486, -0.8947620933045725, -0.8939804559682891, -0.8931933404003516, -0.892400713079872, -0.8916025403536288, -0.8907987884366952, -0.8899894234130917, -0.8891744112364617, -0.8883537177307711, -0.8875273085910325, -0.8866951493840524, -0.8858572055492046, -0.8850134423992284, -0.8841638251210511, -0.8833083187766378, -0.8824468883038663, -0.8815794985174281, -0.8807061141097572, -0.8798266996519848, -0.878941219594922, -0.8780496382700704, -0.8771519198906597, -0.8762480285527146, -0.8753379282361504, -0.8744215828058973, -0.8734989560130535, -0.8725700114960693, -0.8716347127819606, -0.8706930232875522, -0.869744906320753, -0.8687903250818614, -0.8678292426649025, -0.8668616220589966, -0.8658874261497609, -0.8649066177207418, -0.8639191594548821, -0.8629250139360195, -0.86192414365042, -0.8609165109883439, -0.8599020782456466, -0.8588808076254141, -0.8578526612396329, -0.856817601110895, -0.855775589174139, -0.8547265872784261, -0.8536705571887534, -0.852607460587903, -0.8515372590783284, -0.8504599141840773, -0.849375387352753, -0.8482836399575129, -0.847184633299106, -0.8460783286079477, -0.8449646870462346, -0.8438436697100982, -0.8427152376317971, -0.8415793517819513, -0.8404359730718141, -0.8392850623555859, -0.8381265804327689, -0.8369604880505621, -0.8357867459062983, -0.8346053146499223, -0.8334161548865118, -0.8322192271788401, -0.8310144920499815, -0.8298019099859595, -0.8285814414384387, -0.8273530468274595, -0.8261166865442167, -0.8248723209538826, -0.8236199103984744, -0.8223594151997645, -0.8210907956622387, -0.8198140120760964, -0.8185290247202979, -0.8172357938656573, -0.81593427977798, -0.8146244427212479, -0.8133062429608491, -0.8119796407668555, -0.8106445964173468, -0.809301070201781, -0.8079490224244125, -0.8065884134077569, -0.8052192034961044, -0.80384135305908, -0.8024548224952512, -0.8010595722357858, -0.799655562748155, -0.7982427545398869, -0.7968211081623683, -0.7953905842146939, -0.7939511433475658, -0.7925027462672406, -0.7910453537395261, -0.7895789265938273, -0.7881034257272405, -0.7866188121086977, -0.7851250467831598, -0.7836220908758593, -0.782109905596592, -0.7805884522440585, -0.7790576922102551, -0.7775175869849139, -0.7759680981599926, -0.7744091874342136, -0.7728408166176522, -0.771262947636375, -0.7696755425371268, -0.7680785634920665, -0.7664719728035536, -0.7648557329089823, -0.7632298063856651, -0.7615941559557649, -0.7599487444912771, -0.7582935350190586, -0.7566284907259059, -0.7549535749636815, -0.7532687512544889, -0.7515739832958932, -0.7498692349661928, -0.7481544703297354, -0.746429653642282, -0.7446947493564187, -0.7429497221270138, -0.7411945368167219, -0.739429158501533, -0.7376535524763688, -0.7358676842607217, -0.7340715196043415, -0.7322650244929643, -0.7304481651540864, -0.7286209080627816, -0.7267832199475612, -0.7249350677962783, -0.7230764188620713, -0.721207240669352, -0.7193275010198336, -0.7174371679985985, -0.7155362099802073, -0.7136245956348475, -0.7117022939345188, -0.7097692741592596, -0.7078255059034086, -0.7058709590819046, -0.703905603936621, -0.7019294110427388, -0.6999423513151498, -0.6979443960148981, -0.6959355167556516, -0.6939156855102075, -0.6918848746170292, -0.6898430567868128, -0.6877902051090852, -0.6857262930588288, -0.6836512945031366, -0.6815651837078924, -0.6794679353444786, -0.6773595244965075, -0.6752399266665783, -0.6731091177830562, -0.6709670742068736, -0.6688137727383526, -0.6666491906240466, -0.6644733055636015, -0.6622860957166337, -0.6600875397096247, -0.6578776166428313, -0.6556563060972085, -0.6534235881413468, -0.6511794433384197, -0.6489238527531414, -0.6466567979587337, -0.6443782610439008, -0.6420882246198091, -0.6397866718270722, -0.6374735863427397, -0.6351489523872873, -0.6328127547316077, -0.630464978704, -0.6281056101971566, -0.6257346356751469, -0.6233520421803939, -0.6209578173406449, -0.6185519493759326, -0.6161344271055263, -0.6137052399548707, -0.6112643779625107, -0.6088118317870018, -0.606347592713803, -0.6038716526621499, -0.6013840041919087, -0.5988846405104074, -0.5963735554792423, -0.5938507436210596, -0.5913162001263084, -0.5887699208599646, -0.5862119023682238, -0.58364214188516, -0.5810606373393495, -0.5784673873604582, -0.5758623912857893, -0.5732456491667901, -0.5706171617755161, -0.5679769306110503, -0.5653249579058751, -0.562661246632196, -0.5599858005082137, -0.557298624004344, -0.5545997223493823, -0.5518891015366106, -0.5491667683298466, -0.5464327302694305, -0.5436869956781494, -0.540929573667095, -0.5381604741414564, -0.5353797078062397, -0.5325872861719194, -0.5297832215600138, -0.5269675271085849, -0.5241402167776605, -0.5213013053545766, -0.5184508084592355, -0.5155887425492811, -0.5127151249251873, -0.5098299737352566, -0.5069333079805285, -0.5040251475195945, -0.5011055130733177, -0.49817442622945507, -0.49523190944717976, -0.4922779860615022, -0.48931268028758673, -0.48633601722496234, -0.48334802286162554, -0.4803487240780326, -0.47733814865097934, -0.47431632525736667, -0.4712832834778494, -0.4682390538003662, -0.465183667623549, -0.46211715726000974, -0.45903955593950185, -0.45595089781195497, -0.4528512179503811, -0.44974055235364957, -0.44661893794912927, -0.44348641259519583, -0.4403430150836026, -0.43718878514171233, -0.434023763434589, -0.43084799156694653, -0.4276615120849539, -0.4244643684778938, -0.42125660517967356, -0.4180382675701865, -0.41480940197652194, -0.41157005567402244, -0.40832027688718564, -0.4050601147904106, -0.40178961950858566, -0.39850884211751697, -0.3952178346441962, -0.3919166500669051, -0.38860534231515714, -0.3852839662694723, -0.3819525777609865, -0.3786112335708921, -0.3752599914297089, -0.3718989100163851, -0.3685280489572257, -0.3651474688246483, -0.36175723113576447, -0.35835739835078595, -0.3549480338712546, -0.3515292020380951, -0.34810096812948943, -0.3446633983585721, -0.34121655987094607, -0.33776052074201707, -0.3342953499741476, -0.330821117493628, -0.3273378941474652, -0.32384575169998836, -0.3203447628292705, -0.316835001123366, -0.31331654107636375, -0.3097894580842551, -0.3062538284406168, -0.3027097293321085, -0.2991572388337846, -0.2955964359042207, -0.2920274003804542, -0.2884502129727393, -0.28486495525911637, -0.2812717096797961, -0.2776705595313584, -0.2740615889607664, -0.2704448829591958, -0.2668205273556803, -0.26318860881057343, -0.2595492148088268, -0.2559024336530864, -0.25224835445660676, -0.2485870671359841, -0.24491866240370913, -0.2412432317605406, -0.2375608674877001, -0.23387166263888975, -0.230175711032133, -0.22647310724144054, -0.22276394658830218, -0.21904832513300543, -0.21532633966578324, -0.2115980876977913, -0.20786366745191664, -0.2041231778534196, -0.20037671852040992, -0.19662438975415913, -0.1928662925292509, -0.18910252848357115, -0.1853331999081395, -0.18155840973678453, -0.177778261535664, -0.1739928594926332, -0.17020230840646236, -0.16640671367590604, -0.16260618128862664, -0.15880081780997396, -0.1549907303716235, -0.15117602666007585, -0.14735681490501934, -0.1435332038675591, -0.13970530282831423, -0.1358732215753865, -0.13203707039220292, -0.12819696004523476, -0.12435300177159621, -0.12050530726652509, -0.11665398867074886, -0.11279915855773871, -0.10894092992085458, -0.10507941616038445, -0.1012147310704807, -0.09734698882599686, -0.09347630396922774, -0.08960279139655628, -0.0857265663450104, -0.08184774437873295, -0.07796644137536819, -0.0740827735123683, -0.07019685725322307, -0.0663088093336163, -0.062418746747512514, -0.05852678673317719, -0.05463304675913431, -0.05073764451006459, -0.04684069787264808, -0.042942324921354615, -0.03904264390418592, -0.03514177322837281, -0.031239831446031256, -0.02733693723978106, -0.023433209408330664, -0.019528766852031983, -0.015623728558408866, -0.011718213587663012, -0.007812341058161014, -0.00390623013190634, 0.0, 0.00390623013190634, 0.007812341058161014, 0.011718213587663012, 0.015623728558408866, 0.019528766852031983, 0.023433209408330664, 0.02733693723978106, 0.031239831446031256, 0.03514177322837281, 0.03904264390418592, 0.042942324921354615, 0.04684069787264808, 0.05073764451006459, 0.05463304675913431, 0.05852678673317719, 0.062418746747512514, 0.0663088093336163, 0.07019685725322307, 0.0740827735123683, 0.07796644137536819, 0.08184774437873295, 0.0857265663450104, 0.08960279139655628, 0.09347630396922774, 0.09734698882599686, 0.1012147310704807, 0.10507941616038445, 0.10894092992085458, 0.11279915855773871, 0.11665398867074886, 0.12050530726652509, 0.12435300177159621, 0.12819696004523476, 0.13203707039220292, 0.1358732215753865, 0.13970530282831423, 0.1435332038675591, 0.14735681490501934, 0.15117602666007585, 0.1549907303716235, 0.15880081780997396, 0.16260618128862664, 0.16640671367590604, 0.17020230840646236, 0.1739928594926332, 0.177778261535664, 0.18155840973678453, 0.1853331999081395, 0.18910252848357115, 0.1928662925292509, 0.19662438975415913, 0.20037671852040992, 0.2041231778534196, 0.20786366745191664, 0.2115980876977913, 0.21532633966578324, 0.21904832513300543, 0.22276394658830218, 0.22647310724144054, 0.230175711032133, 0.23387166263888975, 0.2375608674877001, 0.2412432317605406, 0.24491866240370913, 0.2485870671359841, 0.25224835445660676, 0.2559024336530864, 0.2595492148088268, 0.26318860881057343, 0.2668205273556803, 0.2704448829591958, 0.2740615889607664, 0.2776705595313584, 0.2812717096797961, 0.28486495525911637, 0.2884502129727393, 0.2920274003804542, 0.2955964359042207, 0.2991572388337846, 0.3027097293321085, 0.3062538284406168, 0.3097894580842551, 0.31331654107636375, 0.316835001123366, 0.3203447628292705, 0.32384575169998836, 0.3273378941474652, 0.330821117493628, 0.3342953499741476, 0.33776052074201707, 0.34121655987094607, 0.3446633983585721, 0.34810096812948943, 0.3515292020380951, 0.3549480338712546, 0.35835739835078595, 0.36175723113576447, 0.3651474688246483, 0.3685280489572257, 0.3718989100163851, 0.3752599914297089, 0.3786112335708921, 0.3819525777609865, 0.3852839662694723, 0.38860534231515714, 0.3919166500669051, 0.3952178346441962, 0.39850884211751697, 0.40178961950858566, 0.4050601147904106, 0.40832027688718564, 0.41157005567402244, 0.41480940197652194, 0.4180382675701865, 0.42125660517967356, 0.4244643684778938, 0.4276615120849539, 0.43084799156694653, 0.434023763434589, 0.43718878514171233, 0.4403430150836026, 0.44348641259519583, 0.44661893794912927, 0.44974055235364957, 0.4528512179503811, 0.45595089781195497, 0.45903955593950185, 0.46211715726000974, 0.465183667623549, 0.4682390538003662, 0.4712832834778494, 0.47431632525736667, 0.47733814865097934, 0.4803487240780326, 0.48334802286162554, 0.48633601722496234, 0.48931268028758673, 0.4922779860615022, 0.49523190944717976, 0.49817442622945507, 0.5011055130733177, 0.5040251475195945, 0.5069333079805285, 0.5098299737352566, 0.5127151249251873, 0.5155887425492811, 0.5184508084592355, 0.5213013053545766, 0.5241402167776605, 0.5269675271085849, 0.5297832215600138, 0.5325872861719194, 0.5353797078062397, 0.5381604741414564, 0.540929573667095, 0.5436869956781494, 0.5464327302694305, 0.5491667683298466, 0.5518891015366106, 0.5545997223493823, 0.557298624004344, 0.5599858005082137, 0.562661246632196, 0.5653249579058751, 0.5679769306110503, 0.5706171617755161, 0.5732456491667901, 0.5758623912857893, 0.5784673873604582, 0.5810606373393495, 0.58364214188516, 0.5862119023682238, 0.5887699208599646, 0.5913162001263084, 0.5938507436210596, 0.5963735554792423, 0.5988846405104074, 0.6013840041919087, 0.6038716526621499, 0.606347592713803, 0.6088118317870018, 0.6112643779625107, 0.6137052399548707, 0.6161344271055263, 0.6185519493759326, 0.6209578173406449, 0.6233520421803939, 0.6257346356751469, 0.6281056101971566, 0.630464978704, 0.6328127547316077, 0.6351489523872873, 0.6374735863427397, 0.6397866718270722, 0.6420882246198091, 0.6443782610439008, 0.6466567979587337, 0.6489238527531414, 0.6511794433384197, 0.6534235881413468, 0.6556563060972085, 0.6578776166428313, 0.6600875397096247, 0.6622860957166337, 0.6644733055636015, 0.6666491906240466, 0.6688137727383526, 0.6709670742068736, 0.6731091177830562, 0.6752399266665783, 0.6773595244965075, 0.6794679353444786, 0.6815651837078924, 0.6836512945031366, 0.6857262930588288, 0.6877902051090852, 0.6898430567868128, 0.6918848746170292, 0.6939156855102075, 0.6959355167556516, 0.6979443960148981, 0.6999423513151498, 0.7019294110427388, 0.703905603936621, 0.7058709590819046, 0.7078255059034086, 0.7097692741592596, 0.7117022939345188, 0.7136245956348475, 0.7155362099802073, 0.7174371679985985, 0.7193275010198336, 0.721207240669352, 0.7230764188620713, 0.7249350677962783, 0.7267832199475612, 0.7286209080627816, 0.7304481651540864, 0.7322650244929643, 0.7340715196043415, 0.7358676842607217, 0.7376535524763688, 0.739429158501533, 0.7411945368167219, 0.7429497221270138, 0.7446947493564187, 0.746429653642282, 0.7481544703297354, 0.7498692349661928, 0.7515739832958932, 0.7532687512544889, 0.7549535749636815, 0.7566284907259059, 0.7582935350190586, 0.7599487444912771, 0.7615941559557649, 0.7632298063856651, 0.7648557329089823, 0.7664719728035536, 0.7680785634920665, 0.7696755425371268, 0.771262947636375, 0.7728408166176522, 0.7744091874342136, 0.7759680981599926, 0.7775175869849139, 0.7790576922102551, 0.7805884522440585, 0.782109905596592, 0.7836220908758593, 0.7851250467831598, 0.7866188121086977, 0.7881034257272405, 0.7895789265938273, 0.7910453537395261, 0.7925027462672406, 0.7939511433475658, 0.7953905842146939, 0.7968211081623683, 0.7982427545398869, 0.799655562748155, 0.8010595722357858, 0.8024548224952512, 0.80384135305908, 0.8052192034961044, 0.8065884134077569, 0.8079490224244125, 0.809301070201781, 0.8106445964173468, 0.8119796407668555, 0.8133062429608491, 0.8146244427212479, 0.81593427977798, 0.8172357938656573, 0.8185290247202979, 0.8198140120760964, 0.8210907956622387, 0.8223594151997645, 0.8236199103984744, 0.8248723209538826, 0.8261166865442167, 0.8273530468274595, 0.8285814414384387, 0.8298019099859595, 0.8310144920499815, 0.8322192271788401, 0.8334161548865118, 0.8346053146499223, 0.8357867459062983, 0.8369604880505621, 0.8381265804327689, 0.8392850623555859, 0.8404359730718141, 0.8415793517819513, 0.8427152376317971, 0.8438436697100982, 0.8449646870462346, 0.8460783286079477, 0.847184633299106, 0.8482836399575129, 0.849375387352753, 0.8504599141840773, 0.8515372590783284, 0.852607460587903, 0.8536705571887534, 0.8547265872784261, 0.855775589174139, 0.856817601110895, 0.8578526612396329, 0.8588808076254141, 0.8599020782456466, 0.8609165109883439, 0.86192414365042, 0.8629250139360195, 0.8639191594548821, 0.8649066177207418, 0.8658874261497609, 0.8668616220589966, 0.8678292426649025, 0.8687903250818614, 0.869744906320753, 0.8706930232875522, 0.8716347127819606, 0.8725700114960693, 0.8734989560130535, 0.8744215828058973, 0.8753379282361504, 0.8762480285527146, 0.8771519198906597, 0.8780496382700704, 0.878941219594922, 0.8798266996519848, 0.8807061141097572, 0.8815794985174281, 0.8824468883038663, 0.8833083187766378, 0.8841638251210511, 0.8850134423992284, 0.8858572055492046, 0.8866951493840524, 0.8875273085910325, 0.8883537177307711, 0.8891744112364617, 0.8899894234130917, 0.8907987884366952, 0.8916025403536288, 0.892400713079872, 0.8931933404003516, 0.8939804559682891, 0.8947620933045725, 0.8955382857971486, 0.8963090667004403, 0.8970744691347852, 0.897834526085895, 0.898589270404339, 0.8993387348050462, 0.9000829518668307, 0.9008219540319365, 0.9015557736056028, 0.9022844427556502, 0.9030079935120863, 0.9037264577667303, 0.9044398672728585, 0.9051482536448664, 0.9058516483579518, 0.9065500827478152, 0.9072435880103779, 0.9079321952015192, 0.9086159352368307, 0.9092948388913872, 0.9099689367995354, 0.9106382594546996, 0.9113028372092032, 0.9119627002741072, 0.9126178787190637, 0.9132684024721864, 0.9139143013199357, 0.9145556049070189, 0.9151923427363066, 0.9158245441687624, 0.9164522384233875, 0.9170754545771808, 0.9176942215651103, 0.9183085681801013, 0.9189185230730362, 0.919524114752768, 0.9201253715861468, 0.92072232179806, 0.9213149934714836, 0.9219034145475472, 0.9224876128256104, 0.9230676159633514, 0.9236434514768671, 0.9242151467407852, 0.9247827289883869, 0.925346225311741, 0.9259056626618496, 0.9264610678488026, 0.9270124675419444, 0.9275598882700505, 0.9281033564215134, 0.9286428982445389, 0.9291785398473523, 0.9297103071984134, 0.9302382261266414, 0.9307623223216483, 0.931282621333982, 0.9317991485753769, 0.9323119293190149, 0.932820988699792, 0.9333263517145964, 0.9338280432225917, 0.9343260879455095, 0.9348205104679493, 0.9353113352376858, 0.9357985865659837, 0.9362822886279191, 0.936762465462709, 0.9372391409740465, 0.937712338930443, 0.9381820829655777, 0.9386483965786518, 0.9391113031347509, 0.939570825865212, 0.940026987867997, 0.9404798121080715, 0.9409293214177904, 0.9413755384972874, 0.9418184859148706, 0.9422581861074242, 0.9426946613808131, 0.9431279339102947, 0.943558025740934, 0.9439849587880237, 0.9444087548375099, 0.94482943554642, 0.9452470224432973, 0.9456615369286379, 0.9460730002753329, 0.9464814336291137, 0.9468868580090015, 0.9472892943077605, 0.9476887632923543, 0.9480852856044063, 0.948478881760663, 0.9488695721534608, 0.9492573770511957, 0.9496423165987963, 0.9500244108181993, 0.9504036796088287, 0.9507801427480761, 0.9511538198917856, 0.9515247305747395, 0.9518928942111476, 0.9522583300951382, 0.9526210574012511, 0.952981095184934, 0.953338462383039, 0.9536931778143231, 0.9540452601799487, 0.9543947280639877, 0.9547415999339255, 0.9550858941411678, 0.955427628921549, 0.955766822395841, 0.9561034925702643, 0.9564376573370004, 0.9567693344747047, 0.9570985416490212, 0.9574252964130979, 0.9577496162081036, 0.958071518363745, 0.9583910200987853, 0.9587081385215631, 0.9590228906305123, 0.9593352933146825, 0.95964536335426, 0.9599531174210895, 0.9602585720791958, 0.9605617437853068, 0.9608626488893753, 0.9611613036351028, 0.9614577241604624, 0.9617519264982222, 0.9620439265764688, 0.9623337402191307, 0.9626213831465018, 0.9629068709757654, 0.9631902192215166, 0.963471443296286, 0.9637505585110627 };
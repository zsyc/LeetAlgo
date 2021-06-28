def removeDuplicates(s: str) -> str:
    i = 0
    while i < len(s)-1:
        if s[i] == s[i+1]:
            s = s[i+2:] if s==0 else s[:i]+s[i+2:]
            i = 0 if i==0 else i-1
        else:
            i+=1
    return s   

print(removeDuplicates("gnyogdbncigrwnjjtqtyregqyhkinjxgzmkpxskloxjcensflhhxlpfkrcmuctrrqahjlmziiupsenyaagbamdkxgqswexvffjygshlkcvdmjypmpduactfnlezrltjirqntomjomkkjdotvlfjafboajhklqvboluugoorigqswfzblnzqmxrootnudnqenmtffuzhallvqmlvmhvulbasxmbtfytqrpdxthbfezwfmaenimwnjhxjhtncyhmlazjjlqxtavunztuhhxduzbwnunjeiorsjnqqtkpoomfpoomshvaolvhkaeldunxvaheorqjjsvbxijmeftlsglnijdfgnpeisacakcyogdvwaeanzinmzecqzptmaqymdtcnctdyqukzxjjoqgllpyzmoaqdbiurwgdnxzaavdvjfoplymjkhzailvdqoohdrwihokdxzfqnnpsccfwfappvpozccxfefflqpstzzxvjpgdwenirlsxfkcstwvuatmturxgczkriaalhoqylrnrullmqajxrxvmkeyrcogpjwralyvxhdinhsfeksbwdtywbdnmucgdukrcltsjqehvkbhqmhvarpupvgwxqydnbrvmxmqlddaqvalnewursnrvlcofejwjryexpvglkyjkrgigpewxdbfoacmnxjqzqumtjmyjcmnukfotapbfybhnnbgtnyvneoiiiabqonoqaykrtopgdvcnwcfhqeamvbwzgmzrjegszfzgxfasgvicxqxmllgvhqzypaapfrjrmgrwdpcvfgdgkmkwmlyymybryxyunjzglpfqbwhihtsvujejryntmqldlgtegkwxmzwfqjexuiznzycstunbzpcfrlmocijwoclexdzdkkgeflesklphhsqteplpscgsjhfrmxmwstpljhsvcqyuscnvuadidyprjqyoygvgwozqigmxtstoetsfjvvdpmmfbfnpijjybxquvfaxsfrzlecwboqqlqbffhqaynmfhfbanspotydwtdllbolveyjwrkrvnpcdmgtsikrfylusoyyqrpglmviwqzebuoxslildwbjlimytbsvrypkwgdqdcwxkbtlvklhiwhytbqycipvtuiuebszihybdrzpobnszrdhdltnnrbqbvqxjrpltvxydhmwbwswkgxzrpupoxhtdercsvhkizpjwqlqtncvyufaxtjdznojtvbplgfzgtuvrtuujfhxcxupddmduklodecnxtlgszswmowszfrqakrqnsvnvipyadbruuknkijpphdtbkxveyijdoaflwdetbagvqhksabyapmvlufeftzfkvxzrhasuianvslpfcikzrdvghokiwntuouiadysnghymcyvnworaecsffciwsmrxzcsopmifigkxbqmdsgtelajmgabzxgsqqtanmkebcpwudwwsmtfaqrxiyohfymgqcifgyvydqtpvzbrhwhntnhwrflrrayknllojkdijbbupaklzvpzlxofjiidyllitjtgxfvhxzhxbngdjvbamlouxrtfzgtfqyuthhlhiiwropqlsxazzqcjpomvwctotidohpaavhvuiwljdzeycjasacdedxpdlkxkqukhueicdxdzrbgpagenspiyuguowbmsydcxfldnfdstyqeacyrdbrbicepwevbhugzecqengmpadgkksqyycnqeilfyomjtmyulgavbogsibfoajcoqsblehgvivoibhkwuulvzawebjbusbpnthtidkgivptcwqgeealdmmsfzdlsksqyvfogzxirsyupfphvndljblgiklherznezjoqratdpaubvdicijbqiemtcfjghzxkbrryttfhpusfbkhmgmmoexltbhsoflpqdmwvhpgzkdqwpszznjimvlwhmwqpinnorgjpptpwxpwgagtubszwvgiczsfzwrmvrjwvwupapsiolbzbjitxjedfyughkzpkhujvkahsxyblsewzanydmzwlgmjvftwmsbjecdosfikvhjrqqhxmehavbyeemteuqvgoxjkpgvgrlabpypckbkkoqfauyuqojtmxmyzwgtxfgxqoxaahzpkbrbtuymrgdxmrfqmwbrpjnkqzdolptzcwmnvjxkbdahyytikvvbandzfhjjbaogoxxfyjbraqjjmoyiibmfterpaxrkreymmtpfjvztgquwbxkxrvfkegvaxwktzhvfrykrvsyrixjpfrbmzcoszektofgdpdfvqsbjfygregsygkhdfndqhoijkzloradgzbwjpnavwzdrnvptsdgfmapqmhaoakadjybfqgorzcnkaojmcotombnchjdskxavyrjtpwcjgaoilcyvqalofltksjildedotsitktyzenywwvtttuyimlnbtoxlazvmjiwvvdeikdzmuitdbxufvtdmypsunrpdnqxfcobdkfvsojfwnifscjcvypndgbyjqntwfxflyktjbpjqsnfkqpbwuahoyhgeoouulkbcnfkqlxqfynefjkwitpsmnsrhficxzcyobzodyvrvskzqeivwytfpjnqmmiuyvvzsmuqyqkolvaccbyqixtbljwhisxilhadwqejoazilbizmuzyolnfpvxfguikclbsdsgpdtezexgcrlbkkpgnftwtqtdfztkhwxwbhwlcxeinmsiiivskkrjpvznuukjzxiyajbpduurpakyigieabqdiopchzechzllywazexaqiegwmldblzylsxahzspbgwnvfklluljgolyztuonjxxhpwkyuykafgvparuerfyynxygqhtelsildgeqvcsxkmpteyotadxwnxcybayrlgvtkmlsaxcoalarzbvgbonaafidquicefrcrytzgqgxosduscpilmbbrlnriyrfsracyctdmunsmzoytixvdgrroyfapjwztamzurqwcdcbqmwvhorwtjukxjbhktvwmqhysoyvcwzzprewkgmjcfdhhohgimpzltltzxinlpukbcaevgghltiwnlbozzfitkxncpjjminjzjrhvxbgvfcuzfcpsdlcklxmbdfafqixwlmfyuckxdoyeqceiqqxysygjdlwrzkiqwihaqotvacvuadhwlfcpgazbpahgmxhqnbjuuwnkdrbtypuboeiwendakeejucjudqjwvbuqfemilgvytqsjismxlgrqltwekymjlyqzeqpjhdgacklbsfyspxnqxcyqzvqmgihhuhpbavrhdpkjqmvusvkemobcmmmuostueklvejcoyqmsjlgiuzzypvxjlvskzlkntyaiippsurcowvrnymwukxazmfnurbjgidyjzbgmqwjcfmnssdebzkavddltmsooxgbczfjhpiammeuhnzqdushgcadvluimeysgtjyznyqqqmenmadaborhcncuqutravcrthhfmthsbicnfevimbpbishsrraksjwlvdwonecuvoeevmyhmtxstkvlxenpmkkygiiyqzfrsvpxrpflpccnzvnqnbexajvciibqkhzvizcgvwnetisxyailxkrxjkkoankqyigyrmjclaqrzxyffkzcnnfhwgqgmiwpkjtgnjwvohconiugobjtnxpevvvqsxtrvhbdmmjjltkxlfkselygkyjkbkktzwqadejsgxwsqhxrjgsgmqxmlwnqbotshysrhyqpxqbiqlyzxanxcqwryaeadjjhlbpgwrfixaialnjtplrgxiafbslmjmblexbuczzllrkivtjoyinaxhdaxeklkakwgtifpdnepryvqekumvhvkqwqdhvxnmxivhsosiwhbfysmdenpcyqvjfgldyfiusdxtliiprkkdvmdzwcmgkitpbsxoyzucuijiljjgvopispzuwtltkidxsybztgyczzsgvudyvvwejqqdqjatodzltqucgnstoemxcotgqdvdrzytddqamurevcpndikbsrfhgiitwrzpaecookkciybfvwmodedewgofydbfqfgwuhyjuhskdpdtujducgoxogjfsouqkhkfplnvoqywnwnonrltolbgzjohdxlwobucbuwghkdulemgryelbclvwkwijlsyrlzocybrqhcfmpovcbmfvfikegaqpdzkpvbfmkezlxpseeisbnwncjlolumwzikksrkxhfkllyureidpmmrtkkvkjbumdnmpxitrlxqlktwrtqdgatdazmqrztrmvknijwormqebfgnfbbncfggmzfvfkzsexmyrxrcvuipjulrmgwvmejztilytfjjyhuutslzhpwasosxqoothdspqinvbjhgrrzbbbmzedhdwfzihznptdggxgflqaiavtctifhlcshebkfajbcdxwngkikdzytddbebzayrphmmobhvvaodgntojbhvaemxzffwqpdmsqjoujbhxjoasbayfpdgjfulvfcrgwslnyqyqdmzfhxvufcotpzdwyhxqsisvonqgsplgsxqogblheybufdwddutmsyfuvfjgyccrfgawhzqejocwjguihzdvyfzeaimvtcdcjqrzcuwzvqrgjrdhjpnfkppprgqvgpivfikpdzkkjkgtusrvujdxltvsrhchzcgdvucnzzyskwdntywzqbwzzarwirgxmokhdixuoqrxhexmsbytnrcfkpxyldalbkqauihsxlcrbqjzzobwsensohnqprzxusmewymtkdfcolfhwxqippmksmlrnlfqlhrenldnjzxqdrtjjygcwqbdhtqicpkqwhmdevlsgmobqosqjmpffoeixbxxrhvrumebtgimhiijhtdrppzhiuhrunmrvzbswlzgvymmgqwihuoflwwhaywajadpfzojkjhdncqtrfpaqqfagvwcntbkdqhzkciwlapkomodmqyxwtquypbbjdefmezkerketzctzdoiislfmleaufovnpabwychebmvxlnkjsfybfuoxsoomxgioiomzauwaspldxwrntkvawlcovclrkfonxdvkazqtzazsanoqwzozlyryyotdxxaiosmfugkrgclmxbvvscmlgbpqmluctdvicyhirqmfvcblaaattivahnrxhhfgxccklbrcbvlbkjwpultvhathockapgjhtrkfrdqrreantgyishlmqmwxubmyxvjdmelwatuqgticskxchgzfueeglpizljgqwdwcowuvmeufsscdgljkobyqikworwzgddwdasgwehoxxcvdxykualubmrzhtwvvrpnburqtuygvzjuypuojbcuaiqidfywduhpuyqfksxzooadifrokqjxmrpqmdmakpbnswdhtfzmxsivqeervgfzyrmyftnoxauluiiecabgmoquqtywzwgkltrgzygxeuphhpgydtyxnobwfornvqitfcwatqjnogpteroweniwnkeehkgnahxaaqsdgvwbltozxewnqblchuacnkpzjxgvaoywrufaseezukagdoabsqmihrctxmcxgstcjsxvdxqzodlfezoegtwzkkoshhxcsfzkzbyclhhjfxzspjfewflnfyspwupkrvwyykgvzhwhabxpdofyaeryazdqfmlipwtlnlfadqnbwfnrqrzceigjrcbubuoonhywhcxajdclvpbnrjcxxbvgyyganyqszugltgonbynqzvqoflqkxwijvdemyobvbmkqctfbpmpcdxpwcmmbupmkefntdldjvrkqukotlebzwyenuajedcgwjrrcqhfktzvlysxbjpauhkjrfkvudtefkdxsaywuhqjbwybfcorchxdcleidjwafrqxlcmcmrxkmpzcazdgdlxyxoebzknsxrdsobttyncpgdxccoxhqmohiwwtqgflnedlavzisporhtbhzizggmwarrckwowcxhzyvjpbvbatduzrudsmezkhzfxchyizgsjwsllmplbtcdtotkzepwsrrddmwvpgwmwhqsnfkyhzmfhymzwhhvqgnixjsqtrxvrdjdbitwxrlnuovbwtqrtnqmauznxhqlsoylhtummzrkopngaelgmjzgsbotpndmimipiozinfxnskmqbuzjhwnmuoxwrngfrplzytzlzmfhvwgvcldmzmauvhhovriwzkixrmshtanxacgryjamqbsfakxynmlylqgirberwaaaaauczpsgscppglpndnnnqdlgospkypvafxiwspkhsobxgvsemqvtmpsluigwmdwqipzrkeyawxxplibsenftdymuavxvnxuutqvzwjbezzgrlpzmpmvjfyudcbqdjhkrmhykjoaiywqvnzrhfihenbwlenwibzldkyrsdqfrcfrlgkbkkscceohmlobydzsphyoitoaoexrdcqjsfkopecyywgazzfftugzykmtymuurwikeoivibpfwtxvekpidkbgrnqkgdwvyofxpnxihgrpahtkwlackzawblhhevosqpodrcxnljqikojnpmhonbogxnvszqlxmrfpjkiwcbsflawkejxnnhtdtzxpnmhdggshhrgapvptobkkogamtdpzeuskdhiyuhkeysxbktqneiqmfksxklqrxfozpakjjmiiqwljdmkgqzgwssqbpjsiqzmumpiynjuwknkdozxicwcdliabidlovhqpkcpjbnwprjnvxxlqzbfcisxxvtltolvslqrgsjqlibhtmlzppcfqriyovojwliqlgyybyrkopnhxfmwtliozuvfjwovqyjhayojbnlkegveqoahwdnpdnaxcbzrnjlqmmlvprejbbjpytaizkjdsalkvsjkxhhohlhkpasgkkdsnvbnwaiwzlaeryuuorxevqwqfevlegfnavetxgykukwoazrjkzimbecpllxuoeonnfcdekzurlphocsqfwhvidekpojgongdguzzkxshfcygxmtwfxvynrgwoursradnecinkuzhctelpyecxsxlqhstgpqfwkbfxsumxcmczkdopgxbbytegpqbimjpwfcyloenxgluiturfokzalymywqdemncrajozxnyrdgyulacxgmmktpagkrpsdmfbvublbwkouexgoclqozuvgzshudfscnlufbclkbkrubjfrbnhpxxnszcyifmsdykbocwocvqoytozfkgwmeiczobuvwrucfjelntebzblroiqsbteocdptimlcjcuwecbfgrbpwnqmasbrtlyeqezyesnszbjnjnvzabwylchplvadoklzwykazdlambaixczmdhteioflodvscdzrwgedapbvjcbdulvlvqulgbbahxlojejzgavpkfviutyklsmfrcjruljtgtvlifosigvsvybmjbcpfcbxybdqpdkmndcjyyefbjnymfuwvwevhqryoqqfcwwkqwnngjcorpqyealbdqiwktlqkwmuhcckaqtqdspcpcuoshjypfvvcjzmcfcanblrbwpacejfefcjlpcbcqyuisngcjmqhueuliyacwpuztjgunhbetupfpetfhmiskwwygwptpsemeebvvrkumzwkbwshptbhudoctvbidokgwdfvfsxsxzoialdhxlivaztakzteqkfncwzzqxixigjpqjxusexlqdcanidqxtvmktzgvzmqpbkygnoifholvuiimnbrmgduttnlqzyjdksmlcodwerzmnwkkaqhafjtuarcyvxwgvnchvqihbwbhhmsrhifspkaoqvkgdnuktbtdytdnqzifkhxoxqeetbiconkkfwmtsyhkegyuuqikntnhcoblfbljmpbgobskezlqicxmvxwgxzskdalreybmwcafktnuuzcvkuqqhohzejqyqalqxngkprtwrocrafpovbnzlgwpvktxrszdspmstqnlicnokqdcoolftqwifelogwwncnmaustpmexrpqqbvssqfkucwfmsbxjpszqjpysnsvmwbdnchrodyzubnwrptbefojsjeehhyifyqnjrpwbfodhjrhytnfpvzwbwhxqzpblgindehlhinkozsupqrbptortjglaimblyizcbgxxoknpdhpjlrpkdntftgw"))

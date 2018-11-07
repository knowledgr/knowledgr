#pragma once

#include <vector>

namespace colab{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed-east.colabit.com:2001",          // colabit
   "seed-central.colabit.com:2001",       // colabit
   "seed-west.colabit.com:2001",          // colabit
   "colab-seed1.abit-more.com:2001",      // abit
   "52.74.152.79:2001",                   // smooth.witness
   "seed.colabd.com:34191",               // roadscape
   "anyx.co:2001",                        // anyx
   "seed.xeldal.com:12150",               // xeldal
   "seed.colabnodes.com:2001",            // wackou
   "seed.liondani.com:2016",              // liondani
   "gtg.colab.house:2001",                // gtg
   "seed.jesta.us:2001",                  // jesta
   "colabd.pharesim.me:2001",             // pharesim
   "5.9.18.213:2001",                     // pfunk
   "lafonacolab.com:2001",                // lafona
   "seed.rossco99.com:2001",              // rossco99
   "colab-seed.altcap.io:40696",          // ihashfury
   "seed.roelandp.nl:2001",               // roelandp
   "colab.global:2001",                   // klye
   "seed.ecolab.ws:2001",                 // good-karma
   "seed.timcliff.com:2001",              // timcliff
   "104.199.118.92:2001",                 // clayop
   "seed.colabviz.com:2001",              // ausbitbank
   "colab-seed.lukestokes.info:2001",     // lukestokes
   "seed.colabian.info:2001",             // drakos
   "seed.followbtcnews.com:2001",         // followbtcnews
   "node.mahdiyari.info:2001",            // mahdiyari
   "seed.curiecolab.com:2001",            // curie
   "seed.rivercolab.com:2001",            // riverhead
   "148.251.237.104:2001",                // colab-bounty
   "seed1.blockbrothers.io:2001",         // blockbrothers
   "colabseed-fin.privex.io:2001",        // privex
   "seed.jamzed.pl:2001",                 // jamzed
   "seed1.cryptobot.news:2001",           // libertyranger
   "seed.thecryptodrive.com:2001",        // thecryptodrive
   "seed.brandonfrye.us:2001",            // brandonfrye
   "seed.firepower.ltd:2001"              // firepower
};
#endif

} } } // colab::plugins::p2p

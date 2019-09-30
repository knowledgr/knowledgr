# Knowledgr - The Scientific Blockchain

Welcome to Knowledgr, a distributed academic network. It allows for micropublications of academic research, breaking down the scientific method into 4 interactions sent from users:

* Question - Asking a question or asking for additional insight on one user's work
* Observation - Posting a dataset or scientific observation
* Hypothesis - Making a claim (Based off of a previous observation)
* Review - Leaving a peer review in support of or raising comments about another researcher's work

All of these interactions receive votes, and users' voting power comes from an equation made from a few different terms:

- Sigmoid of token stake - this helps reduce spam in the system, while not allowing users to convert wealth into credibility
- Expertise Rating - Voting power scales exponentially with expertise, scores which users have a collection of (integer 1 - 10 in a field of scientific research)
- "Manabar" - This is a decay function that is reduces exponentially, and recovers after a cooldown period. It helps reduce voting spam

Votes are rewarded with a token KNLG. This asset does not have a value currently in a beta network, but in a future version of a network this will act as a currency, rewarding researchers for valuable publications & comments. Additionally, it will allow for a transparent network in a grant system.

# Installation

Getting started with Knowledgr is fairly simple. We recommend using the Ubuntu 18.04 Installation instructions.

## Building

Build from source using these instructions:

https://github.com/norestlabs/knowledgr/blob/master/doc/building.md) for Linux (Ubuntu LTS) and macOS.

## CLI Wallet

We provide a basic cli wallet for interfacing with `knowledgrd`. The wallet is self-documented via command line help. The node you connect to via the cli wallet needs to be running the `account_by_key_api`, `condenser_api`, and needs to be configured to accept WebSocket connections via `webserver-ws-endpoint`.


## Config File

Run `knowledgrd` once to generate a data directory and config file. The default location is `witness_node_data_dir`. Kill `knowledgrd`. It won't do anything without seed nodes. If you want to modify the config to your liking, we have two example configs used in the docker images. ( [consensus node](contrib/config-for-docker.ini), [full node](contrib/fullnode.config.ini) ) All options will be present in the default config file and there may be more options needing to be changed from the docker configs (some of the options actually used in images are configured via command line).

## Seed Nodes

A list of some seed nodes to get you started can be found in
[doc/seednodes.txt](doc/seednodes.txt).

## Environment variables

There are quite a few environment variables that can be set to run knowledgrd in different ways:

* `USE_WAY_TOO_MUCH_RAM` - if set to true, knowledgrd starts a 'full node'
* `USE_FULL_WEB_NODE` - if set to true, a default config file will be used that enables a full set of API's and associated plugins.
* `USE_NGINX_FRONTEND` - if set to true, this will enable an NGINX reverse proxy in front of knowledgrd that proxies WebSocket requests to knowledgrd. This will also enable a custom healthcheck at the path '/health' that lists how many seconds away from current blockchain time your node is. It will return a '200' if it's less than 60 seconds away from being synced.
* `USE_MULTICORE_READONLY` - if set to true, this will enable knowledgrd in multiple reader mode to take advantage of multiple cores (if available). Read requests are handled by the read-only nodes and write requests are forwarded back to the single 'writer' node automatically. NGINX load balances all requests to the reader nodes, 4 per available core. This setting is still considered experimental and may have trouble with some API calls until further development is completed.
* `HOME` - set this to the path where you want knowledgrd to store it's data files (block log, shared memory, config file, etc). By default `/var/lib/knowledgrd` is used and exists inside the docker container. If you want to use a different mount point (like a ramdisk, or a different drive) then you may want to set this variable to map the volume to your docker container.

## System Requirements

For a full web node, you need at least 110GB of disk space available. Knowledgrd uses a memory mapped file which currently holds 56GB of data and by default is set to use up to 80GB. The block log of the blockchain itself is a little over 27GB. It's highly recommended to run knowledgrd on a fast disk such as an SSD or by placing the shared memory files in a ramdisk and using the `--shared-file-dir=/path` command line option to specify where. At least 16GB of memory is required for a full web node. Seed nodes (p2p mode) can run with as little as 4GB of memory with a 24 GB state file. Any CPU with decent single core performance should be sufficient. Knowledgrd is constantly growing. As of August 2017, these numbers were accurate, but you may find you need more disk space to run a full node. We are also constantly working on optimizing Knowledgr's use of disk space.

On Linux use the following Virtual Memory configuration for the initial sync and subsequent replays. It is not needed for normal operation.

```
echo    75 | sudo tee /proc/sys/vm/dirty_background_ratio
echo  1000 | sudo tee /proc/sys/vm/dirty_expire_centisecs
echo    80 | sudo tee /proc/sys/vm/dirty_ratio
echo 30000 | sudo tee /proc/sys/vm/dirty_writeback_centisecs
```

# No Support & No Warranty

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

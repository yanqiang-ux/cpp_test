#include "common/snap_types.h"

#include <map>

#include <iostream>

struct cow_data_t {
  int val = 3;
};

struct cow_inodes_t {
  struct cow_cmp {
    bool operator()(const std::pair<snapid_t, snapid_t> &l,
                    const std::pair<snapid_t, snapid_t> &r) const {
      return false;
      //if (l.second == CEPH_NOSNAP) {
      //  return l.first < r.second;
      //} else if (r.second == CEPH_NOSNAP) {
      //  return l.second < r.first;
      //}
      //return l.first < r.first;
    }
  };

  // cow inodes's oldest snapid
  snapid_t head_first {CEPH_NOSNAP};
  // old cow inodes <<first, last>, inode>
  std::map<std::pair<snapid_t, snapid_t>, cow_data_t, cow_cmp> inodes;
};

int main() {
  cow_inodes_t * cis = new cow_inodes_t();
  cis->inodes[std::make_pair(1, 23)].val = 1;
  //cis->inodes[std::make_pair(1, 24)].val = 2;
  cow_data_t cd;
  cd.val = 2;
  auto it = cis->inodes.insert(std::make_pair( std::make_pair(2, 24), cd));
  std::cout << " success " << it.second << std::endl;
  for (auto &ent : cis->inodes) {
    std::cout << ent.first.second << std::endl;
    std::cout << " hah " << std::endl;
  }
}

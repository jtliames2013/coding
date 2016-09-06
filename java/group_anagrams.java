public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map=new HashMap<String, List<String>>();        
        for (String s:strs) {
            char[] strArray=s.toCharArray();
            Arrays.sort(strArray);
            String key=String.valueOf(strArray);
            
            if (!map.containsKey(key)) map.put(key, new ArrayList<String>());
            map.get(key).add(s);
        }
        
        return new ArrayList<List<String>>(map.values());
    }
}
